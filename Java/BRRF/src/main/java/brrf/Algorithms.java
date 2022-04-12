package brrf;

import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;
import java.util.*;

import static brrf.DatabaseConnector.allTrainsOnStationWithArrTime;
import static brrf.DatabaseConnector.allTrainsOnStationWithDeptTime;
import static brrf.GraphTheory.Graph.pathfinder;
import static brrf.PDFGenerator.generatePDF;
import static brrf.Time.checkIfFirstValueOfTimeIsHigher;
import static brrf.Utilities.matchAny;
import static brrf.Utilities.scheduler;

public class Algorithms {
    private static final String DEPTTIME = "dept_time";
    private static final String ARRTIME = "arr_time";
    private static final String TIMEINCREMENT = "00:01:00";
    private static final String CARRIER = "carrier";
    private static final String SELECTNAMECARRIERFROM = "SELECT name, carrier FROM ";
    private final List<String> spanningTreeResult = new ArrayList<>();


    // --------------- Direct algorithm by Artur Strózik -----------------
    //-----------------------Finding direct routes----------------------------------------------------------------------
    public static List<List<Map<String, Object>>> directRoute(String start, String end,
                                                                   String departureTime, String arrivalTime) {

        List<Map<String, Object>> startStation = allTrainsOnStationWithDeptTime(start, departureTime);
        List<Map<String, Object>> endStation = allTrainsOnStationWithArrTime(end, arrivalTime);

        LinkedList<Map<String, Object>> matchingConnection = new LinkedList<>();
        LinkedList<Map<String, Object>> matchingConnection2 = new LinkedList<>();

        //----------------Finding correct routes------------------------------------------------------------------------
        for (Map<String, Object> stringObjectMap : startStation) {
            for (Map<String, Object> objectMap : endStation) {

                //--------Finding for IC, EIP,and TLK trains------------------------------------------------------------
                if (stringObjectMap.get(CARRIER).toString().equals("IC")
                        || stringObjectMap.get(CARRIER).toString().equals("EIP")
                        || stringObjectMap.get(CARRIER).toString().equals("TLK")) {

                    String startName = stringObjectMap.get("name").toString();
                    startName = startName.substring(0, startName.length() - 2);
                    String endName = objectMap.get("name").toString();
                    endName = endName.substring(0, endName.length() - 2);


                    if (startName.equals(endName) && checkIfFirstValueOfTimeIsHigher(
                            objectMap.get(ARRTIME).toString(),
                            stringObjectMap.get(DEPTTIME).toString())) {

                        matchingConnection.add(stringObjectMap);
                        matchingConnection2.add(objectMap);
                    }

                    //--------Finding for other trains----------------------------------------------------------------------
                } else if (stringObjectMap.get("name").equals(objectMap.get("name")) &&
                        checkIfFirstValueOfTimeIsHigher(objectMap.get(ARRTIME).toString(),
                                stringObjectMap.get(DEPTTIME).toString())) {

                    matchingConnection.add(stringObjectMap);
                    matchingConnection2.add(objectMap);
                }
            }
        }

        //---------------Creating an appropriate array------------------------------------------------------------------

        List<List<Map<String, Object>>> array = new ArrayList<>();
        array.add(matchingConnection);
        array.add(matchingConnection2);

        return array;

    }

    //------------------Selecting only IC, EIP or TLK trains------------------------------------------------------------
    public static List<List<Map<String, Object>>> comfortRoute(List<List<Map<String, Object>>> allPossibleRoutes) {
        LinkedList<Map<String, Object>> matchingConnection = new LinkedList<>();
        LinkedList<Map<String, Object>> matchingConnection2 = new LinkedList<>();

        for (int i = 0; i < allPossibleRoutes.get(0).size(); i++) {
            if (allPossibleRoutes.get(0).get(i).get(CARRIER).toString().equals("IC")
                    || allPossibleRoutes.get(0).get(i).get(CARRIER).toString().equals("EIP")
                    || allPossibleRoutes.get(0).get(i).get(CARRIER).toString().equals("TLK")) {

                matchingConnection.add(allPossibleRoutes.get(0).get(i));
                matchingConnection2.add(allPossibleRoutes.get(1).get(i));
            }

        }

        List<List<Map<String, Object>>> arraycomfort = new ArrayList<>();
        arraycomfort.add(matchingConnection);
        arraycomfort.add(matchingConnection2);

        return arraycomfort;
    }

    // --------------- 'Catch first train and try to get to destination' ----------------
    public List<Train> brrfAlgorithm(Node setOffNode, Node destNode, String deptTime, List<Train> tailTrains, List<String> unvisitedNodes) {
        /*
         * ----------- Define unvisited nodes -----------
         */
        unvisitedNodes.remove(setOffNode.getName());
        List<Train> combination = new ArrayList<>(tailTrains);

        /*
         * ------------ Get db connection -> catch first train and add it to a list --------------
         */
        DataSource dataSource = new DatabaseConnector().postgresDataSource();
        JdbcTemplate jdbcTemplate = new JdbcTemplate(dataSource);
        String initialQuery = SELECTNAMECARRIERFROM + setOffNode.getName() + " WHERE dept_time >= '" +
                deptTime + "' ORDER BY dept_time LIMIT 1";
        List<Map<String, Object>> firstTrain = jdbcTemplate.queryForList(initialQuery);

        // ------------ Look in next day if needed -------------
        if(firstTrain.isEmpty()) {
            String secondQuery = SELECTNAMECARRIERFROM + setOffNode.getName() +
                    " WHERE dept_time >= '00:00:00' ORDER BY dept_time LIMIT 1";
            firstTrain.add(jdbcTemplate.queryForList(secondQuery).get(0));
        }

        // ------ At this stage firstTrain is never null because any station in master database is not null
        Train closestTrain = new Train(firstTrain.get(0).get("name").toString(), firstTrain.get(0).get(CARRIER).toString());
        combination.add(closestTrain);
        closestTrain.readStations();

        // ----- get index at which station is present in sorted list and 'travel' to the end
        int iterator = closestTrain.getStations().indexOf(setOffNode.getName());
        List<String> nextStations = new ArrayList<>();
        boolean targetOnTheRoad = false;
        for (int i = iterator; i < closestTrain.getStations().size(); i++) {
            // ----- add all next stations to check if train visits any visited -> making no point
            nextStations.add(closestTrain.getStations().get(i));
            if (closestTrain.getStations().get(i).equals(destNode.getName())) {
                targetOnTheRoad = true;
            }
        }
        // ------- Remove current station for later station sets comparison --------
        nextStations.remove(setOffNode.getName());

        /*
         * ------- Recursion finish -> if any of next stations is destination
         */
        if (targetOnTheRoad) {
            return combination;
        } else if (combination.size() > 4) {
            // --------- Arbitrary condition to limit recursion ----------
            return Collections.emptyList();
        } else {
            // ---------- If you catch new train on this station, and it goes back -----------
            if (!matchAny(unvisitedNodes, nextStations)) {
                String query = closestTrain.getDeptTime(setOffNode.getName());
                List<Map<String, Object>> askForDeptTime = jdbcTemplate.queryForList(query);
                String queryBackup = closestTrain.getArrTime(setOffNode.getName());
                List<Map<String, Object>> askForArrTime = jdbcTemplate.queryForList(queryBackup);
                Time waitLonger;
                // ----------- If train ends here ------------
                if (askForDeptTime.get(0).get(DEPTTIME) == null) {
                    waitLonger = new Time(askForArrTime.get(0).get(ARRTIME).toString());
                } else {
                    waitLonger = new Time(askForDeptTime.get(0).get(DEPTTIME).toString());
                }
                // --------- we don't want such train :( -----------
                combination.remove(closestTrain);
                return brrfAlgorithm(setOffNode, destNode, waitLonger.addTime("00:05:00"), combination, unvisitedNodes);
            } else {
                // ---------- For each station remove it and do recursive call----------
                List<List<Train>> flatList = new ArrayList<>();
                //Collections.reverse(nextStations);  // ----------- In first order go as far as you can
                for (String each : nextStations) {
                    unvisitedNodes.remove(each);
                    Node input = new Node(each);
                    String query = closestTrain.getDeptTime(input.getName());
                    List<Map<String, Object>> askForDeptTime = jdbcTemplate.queryForList(query);
                    String queryBackup = closestTrain.getArrTime(input.getName());
                    List<Map<String, Object>> askForArrTime = jdbcTemplate.queryForList(queryBackup);
                    if (askForArrTime.get(0).get(ARRTIME) != null) {
                        // --------- If train doesn't depart -> makes no sense to enter it ------------
                        Time exitTime = new Time(askForArrTime.get(0).get(ARRTIME).toString());
                        flatList.add(brrfAlgorithm(input, destNode, exitTime.addTime(TIMEINCREMENT), combination, unvisitedNodes));
                    } else {
                        // --------- but it's important then to find a new one --------
                        Time exitTime = new Time(askForDeptTime.get(0).get(DEPTTIME).toString());
                        flatList.add(brrfAlgorithm(input, destNode, exitTime.addTime(TIMEINCREMENT), combination, unvisitedNodes));
                    }
                }
                return flatList.stream().flatMap(List::stream).toList();
            }
        }
    }

    // ---------- Basic algorithm used to calculate optimal path using Dijkstra's famous algorithm --------
   public List<Train> optimalAlgorithm(Node setOffNode, Node destNode, String deptTime) {/*
    * ------------ Get db connection -> catch first train and add it to a list --------------
    */
       DataSource dataSource = new DatabaseConnector().postgresDataSource();
       JdbcTemplate jdbcTemplate = new JdbcTemplate(dataSource);
       String initialQuery = SELECTNAMECARRIERFROM + setOffNode.getName() + " WHERE dept_time >= '" +
               deptTime + "' ORDER BY dept_time LIMIT 1";
       List<Map<String, Object>> firstTrain = jdbcTemplate.queryForList(initialQuery);
       // ------------ Look in next day if needed -------------
       if (firstTrain.isEmpty()) {
           String secondQuery = SELECTNAMECARRIERFROM + setOffNode.getName() +
                   " WHERE dept_time >= '00:00:00' ORDER BY dept_time LIMIT 1";
           firstTrain.add(jdbcTemplate.queryForList(secondQuery).get(0));
       }
       Train closestTrain = new Train(firstTrain.get(0).get("name").toString(), firstTrain.get(0).get(CARRIER).toString());
       closestTrain.readStations();
       // ----- get index at which station is present in sorted list and 'travel' to the end
       int iterator = closestTrain.getStations().indexOf(setOffNode.getName());
       boolean targetOnTheRoad = false;
       for (int i = iterator; i < closestTrain.getStations().size(); i++) {
           // ----- add all next stations to check if train visits any visited -> making no point
           if (closestTrain.getStations().get(i).equals(destNode.getName())) {
               targetOnTheRoad = true;
           }
       }
       // ------------- Direct train -------------
       List<Train> tab = new ArrayList<>();
       Time timeHolder = new Time(deptTime);
       if (targetOnTheRoad) {
           return List.of(closestTrain);
       } else {
           List<String> path = pathfinder(setOffNode.getName(), destNode.getName());
           spanningTreeResult.addAll(path);
           for (int i = 0; i < path.size() - 1; i++) {
               List<List<Map<String, Object>>> director = directRoute(path.get(i), path.get(i + 1), timeHolder.getTime(), "24:00:00");
               Map<String, Object> departs = new LinkedHashMap<>(director.get(0).get(0));
               Map<String, Object> arrives = new LinkedHashMap<>(director.get(1).get(0));
               Train spline = new Train(departs.get("name").toString(), departs.get(CARRIER).toString());
               tab.add(spline);

               timeHolder = new Time(arrives.get(ARRTIME).toString());
           }
       }

       return tab;
   }

    public List<String> getSpanningTreeResult() {
        return spanningTreeResult;
    }

    public List<List<Map<String, Object>>> findTrainsInDatabase(List<Train> trainList, String startStation, String endStation, boolean isRecursive) {
        List<List<Map<String, Object>>> data = new ArrayList<>();
        List<Map<String, Object>> start = new ArrayList<>();
        List<Map<String, Object>> end = new ArrayList<>();
        List<String> tree = getSpanningTreeResult();

        DataSource dataSource = new DatabaseConnector().postgresDataSource();
        JdbcTemplate jdbcTemplate = new JdbcTemplate();
        jdbcTemplate.setDataSource(dataSource);

        if (isRecursive) {
            List<String> ownSpan = new ArrayList<>();
            ownSpan.add(startStation);
            for (int i = 0; i < trainList.size() - 1; i++) {
                trainList.get(i).readStations();
                List<String> commonStation = trainList.get(i).getStations();
                trainList.get(i + 1).readStations();
                commonStation.retainAll(trainList.get(i + 1).getStations());
                ownSpan.add(commonStation.get(0));
            }
            ownSpan.add(endStation);
            tree = ownSpan;
        }



        if (trainList.size() > 1) {
            for (int i = 0; i < tree.size() - 1; i++) {
                if (Objects.equals(trainList.get(i).getCarrierName(), "IC") || Objects.equals(trainList.get(i).getCarrierName(), "EIP") || Objects.equals(trainList.get(i).getCarrierName(), "TLK")) {
                    String nameHandler;
                    nameHandler = trainList.get(i).getName().substring(0, trainList.get(i).getName().length() - 2);
                    nameHandler = nameHandler + "__";
                    String sql = "SELECT * FROM " + tree.get(i) + " WHERE name LIKE '" + nameHandler + "' ORDER BY dept_time";
                    start.add((jdbcTemplate.queryForList(sql)).get(0));
                    sql = "SELECT * FROM " + tree.get(i + 1) + " WHERE name LIKE '" + nameHandler + "' ";
                    end.add((jdbcTemplate.queryForList(sql)).get(0));
                } else {
                    String sql = "SELECT * FROM " + tree.get(i) + " WHERE name LIKE '" + trainList.get(i).getName() + "' ORDER BY dept_time";
                    start.add((jdbcTemplate.queryForList(sql)).get(0));
                    sql = "SELECT * FROM " + tree.get(i + 1) + " WHERE name LIKE '" + trainList.get(i).getName() + "' ";
                    end.add((jdbcTemplate.queryForList(sql)).get(0));
                }
            }

        } else if (trainList.size() == 1) {
            if (Objects.equals(trainList.get(0).getCarrierName(), "IC") || Objects.equals(trainList.get(0).getCarrierName(), "EIP") || Objects.equals(trainList.get(0).getCarrierName(), "TLK")) {
                String nameHandler;
                nameHandler = trainList.get(0).getName().substring(0, trainList.get(0).getName().length() - 2);
                nameHandler = nameHandler + "__";
                String sql = "SELECT * FROM " + startStation + " WHERE name LIKE '" + nameHandler + "' ORDER BY dept_time";

                start.add((jdbcTemplate.queryForList(sql)).get(0));
                sql = "SELECT * FROM " + endStation + " WHERE name LIKE '" + nameHandler + "' ";
                end.add((jdbcTemplate.queryForList(sql)).get(0));
            } else {
                String sql = "SELECT * FROM " + startStation + " WHERE name LIKE '" + trainList.get(0).getName() + "' ORDER BY dept_time";

                start.add((jdbcTemplate.queryForList(sql)).get(0));
                sql = "SELECT * FROM " + endStation + " WHERE name LIKE '" + trainList.get(0).getName() + "' ";
                end.add((jdbcTemplate.queryForList(sql)).get(0));
            }
        }
        data.add(start);
        data.add(end);

        return data;

    }
}
