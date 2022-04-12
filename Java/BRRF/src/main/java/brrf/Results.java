package brrf;

import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;
import javax.swing.*;
import java.util.Collections;
import java.util.List;
import java.util.Map;

import static brrf.PDFGenerator.generatePDF;
import static brrf.Utilities.scheduler;

public class Results {
    private JLabel firstOptionSetOff;
    private JLabel firstOptionArrTime;
    private JLabel firstOptionDeptStation;
    private JLabel firstOptionArrStation;
    private JPanel resultsApp;
    private JLabel secondOptionSetOff;
    private JLabel secondOptionArrTime;
    private JLabel secondOptionDeptStation;
    private JLabel secondOptionArrStation;
    private JLabel firstOptionHopCount;
    private JLabel secondOptionHopCount;
    private JLabel thirdOptionHopCount;
    private JLabel thirdOptionDeptStation;
    private JLabel thirdOptionArrStation;
    private JLabel thirdOptionSetOff;
    private JLabel thirdOptionArrTime;
    private JLabel fourthOptionHopCount;
    private JLabel fourthOptionDeptStation;
    private JLabel fourthOptionArrStation;
    private JLabel fourthOptionSetOff;
    private JLabel fourthOptionArrTime;
    private JButton generatePDFButton;
    private JPanel firstField;
    private JPanel secondField;
    private JPanel thirdField;
    private JPanel fourthField;
    private JButton firstGeneratePDFButton;
    private JButton secondGeneratePDFButton;
    private JButton thirdGeneratePDFButton;
    private JButton fourthGeneratePDFButton;
    private int trainsAmount = 0;
    List<List<Map<String, Object>>>[] trainSet = new List[4];

    private final JPanel[] options = {firstField, secondField, thirdField, fourthField};

    private final JLabel[][] greatFour = {
            {firstOptionSetOff, firstOptionArrTime, firstOptionDeptStation, firstOptionArrStation, firstOptionHopCount},
            {secondOptionSetOff, secondOptionArrTime, secondOptionDeptStation, secondOptionArrStation, secondOptionHopCount},
            {thirdOptionSetOff, thirdOptionArrTime, thirdOptionDeptStation, thirdOptionArrStation, thirdOptionHopCount},
            {fourthOptionSetOff, fourthOptionArrTime, fourthOptionDeptStation, fourthOptionArrStation, fourthOptionHopCount}
    };

    public Results(String deptStationParam, String arrStationParam, String algorithmParam, String hourParam, String minuteParam) {
        String setArrTimeTemp = hourParam + ":" + minuteParam + ":00";
        if (algorithmParam.equals("Optymalny")) {
            Time arrTimeHolder = new Time(setArrTimeTemp);
            for (int i = 0; i < 4; i++) {
                if (i != 0) {
                    arrTimeHolder.addTime("00:01:00");
                }
                String[] values = arrTimeHolder.getTime().split(":");

                optimalAlgorithmResult(deptStationParam, arrStationParam, values[0], values[1], i);
                arrTimeHolder = new Time(greatFour[i][0].getText() + ":00");
            }
            generatePDFButton.setVisible(false);
        } else if (algorithmParam.equals("Bezpośredni")) {
            Time arrTimeHolder = new Time(setArrTimeTemp);

            String[] values = arrTimeHolder.getTime().split(":");
            directAlgorithmResult(deptStationParam, arrStationParam, values[0], values[1]);

            firstGeneratePDFButton.setVisible(false);
            secondGeneratePDFButton.setVisible(false);
            thirdGeneratePDFButton.setVisible(false);
            fourthGeneratePDFButton.setVisible(false);
        } else if (algorithmParam.equals("Komfortowy")) {
            Time arrTimeHolder = new Time(setArrTimeTemp);

            String[] values = arrTimeHolder.getTime().split(":");
            comfortAlgorithmResult(deptStationParam, arrStationParam, values[0], values[1]);

            firstGeneratePDFButton.setVisible(false);
            secondGeneratePDFButton.setVisible(false);
            thirdGeneratePDFButton.setVisible(false);
            fourthGeneratePDFButton.setVisible(false);
        } else {
            Time arrTimeHolder = new Time(setArrTimeTemp);
            for (int i = 0; i < 4; i++) {
                if (i != 0) {
                    arrTimeHolder.addTime("00:01:00");
                }
                String[] values = arrTimeHolder.getTime().split(":");

                brrfAlgorithmResult(deptStationParam, arrStationParam, values[0], values[1], i);
                arrTimeHolder = new Time(greatFour[i][0].getText() + ":00");
            }
            generatePDFButton.setVisible(false);
        }
        firstGeneratePDFButton.addActionListener(e -> {
            generatePDF(firstOptionDeptStation.getText(), firstOptionArrStation.getText(), firstOptionSetOff.getText(),
                    firstOptionArrTime.getText(), trainSet[0]);
        });
        secondGeneratePDFButton.addActionListener(e -> {
            generatePDF(secondOptionDeptStation.getText(), secondOptionArrStation.getText(), secondOptionSetOff.getText(),
                    secondOptionArrTime.getText(), trainSet[1]);
        });
        thirdGeneratePDFButton.addActionListener(e -> {
            generatePDF(thirdOptionDeptStation.getText(), thirdOptionArrStation.getText(), thirdOptionSetOff.getText(),
                    thirdOptionArrTime.getText(), trainSet[2]);
        });
        fourthGeneratePDFButton.addActionListener(e -> {
            generatePDF(fourthOptionDeptStation.getText(), fourthOptionArrStation.getText(), fourthOptionSetOff.getText(),
                    fourthOptionArrTime.getText(), trainSet[3]);
        });
        generatePDFButton.addActionListener(e -> {
            generatePDF(secondOptionDeptStation.getText(), secondOptionArrStation.getText(), firstOptionSetOff.getText(),
                    fourthOptionArrTime.getText(), trainSet[0]);
        });
    }

    public void optimalAlgorithmResult(String deptStationParam, String arrStationParam, String hourParam, String minuteParam, int index) {
        DataSource dataSource = new DatabaseConnector().stationNamesDataSource();
        JdbcTemplate jdbcTemplate = new JdbcTemplate(dataSource);

        String deptStation = "SELECT english_written FROM names WHERE actual_name = '" + deptStationParam + "'";
        String arrStation = "SELECT english_written FROM names WHERE actual_name = '" + arrStationParam + "'";

        Algorithms test = new Algorithms();
        String star = jdbcTemplate.queryForList(deptStation).get(0).get("english_written").toString();
        String end = jdbcTemplate.queryForList(arrStation).get(0).get("english_written").toString();
        Node start = new Node(star);
        Node cel = new Node(end);
        String timeBuilt = hourParam + ":" + minuteParam + ":00";
        List<Train> journey = test.optimalAlgorithm(start, cel, timeBuilt);
        journey = scheduler(journey);

        List<List<Map<String, Object>>> data = test.findTrainsInDatabase(journey, star, end, false);
        trainSet[index] = data;

        greatFour[index][0].setText(data.get(0).get(0).get("dept_time").toString());
        greatFour[index][1].setText(data.get(1).get(journey.size() - 1).get("arr_time").toString());
        greatFour[index][2].setText(deptStationParam);
        greatFour[index][3].setText(arrStationParam);
        if (journey.size() == 1) {
            greatFour[index][4].setText("Bezpośredni");
        } else {
            greatFour[index][4].setText(journey.size() - 1 + " przesiadki");
        }
    }

    public void directAlgorithmResult(String deptStationParam, String arrStationParam, String hourParam, String minuteParam) {
        DataSource dataSource = new DatabaseConnector().stationNamesDataSource();
        JdbcTemplate jdbcTemplate = new JdbcTemplate();
        jdbcTemplate.setDataSource(dataSource);
        String deptStation = "SELECT english_written FROM names WHERE actual_name = '" + deptStationParam + "'";
        String arrStation = "SELECT english_written FROM names WHERE actual_name = '" + arrStationParam + "'";

        Algorithms test = new Algorithms();
        String star = jdbcTemplate.queryForList(deptStation).get(0).get("english_written").toString();
        String end = jdbcTemplate.queryForList(arrStation).get(0).get("english_written").toString();
        String timeBuilt = hourParam + ":" + minuteParam + ":00";
        List<List<Map<String, Object>>> journey = test.directRoute(star, end, timeBuilt, "24:00:00");
        trainSet[0] = journey;
        if (journey.get(0).size() < 4) {
            trainsAmount = journey.get(0).size();

            for (int i = journey.get(0).size(); i < 4; i++) {
                options[i].setVisible(false);
            }
        } else {
            trainsAmount = 4;
        }

        for (int i = 0; i < trainsAmount; i++) {
            greatFour[i][0].setText(journey.get(0).get(i).get("dept_time").toString());
            greatFour[i][1].setText(journey.get(1).get(i).get("arr_time").toString());
            greatFour[i][2].setText(deptStationParam);
            greatFour[i][3].setText(arrStationParam);
            greatFour[i][4].setText("Bezpośredni");
        }
    }

    public void comfortAlgorithmResult(String deptStationParam, String arrStationParam, String hourParam, String minuteParam) {
        DataSource dataSource = new DatabaseConnector().stationNamesDataSource();
        JdbcTemplate jdbcTemplate = new JdbcTemplate();
        jdbcTemplate.setDataSource(dataSource);
        String deptStation = "SELECT english_written FROM names WHERE actual_name = '" + deptStationParam + "'";
        String arrStation = "SELECT english_written FROM names WHERE actual_name = '" + arrStationParam + "'";

        Algorithms test = new Algorithms();
        String star = jdbcTemplate.queryForList(deptStation).get(0).get("english_written").toString();
        String end = jdbcTemplate.queryForList(arrStation).get(0).get("english_written").toString();
        String timeBuilt = hourParam + ":" + minuteParam + ":00";
        List<List<Map<String, Object>>> journey = test.directRoute(star, end, timeBuilt, "24:00:00");
        journey = test.comfortRoute(journey);
        trainSet[0] = journey;
        if (journey.get(0).size() < 4) {
            trainsAmount = journey.get(0).size();

            for (int i = journey.get(0).size(); i < 4; i++) {
                options[i].setVisible(false);
            }
        } else {
            trainsAmount = 4;
        }

        for (int i = 0; i < trainsAmount; i++) {
            greatFour[i][0].setText(journey.get(0).get(i).get("dept_time").toString());
            greatFour[i][1].setText(journey.get(1).get(i).get("arr_time").toString());
            greatFour[i][2].setText(deptStationParam);
            greatFour[i][3].setText(arrStationParam);
            greatFour[i][4].setText("Bezpośredni");
        }
    }

    public void brrfAlgorithmResult(String deptStationParam, String arrStationParam, String hourParam, String minuteParam, int index) {
        DataSource dataSource = new DatabaseConnector().stationNamesDataSource();
        JdbcTemplate jdbcTemplate = new JdbcTemplate();
        jdbcTemplate.setDataSource(dataSource);
        String deptStation = "SELECT english_written FROM names WHERE actual_name = '" + deptStationParam + "'";
        String arrStation = "SELECT english_written FROM names WHERE actual_name = '" + arrStationParam + "'";

        Algorithms test = new Algorithms();
        MapBuilder map = new MapBuilder();
        List<String> graph = map.getMap();
        String star = jdbcTemplate.queryForList(deptStation).get(0).get("english_written").toString();
        String end = jdbcTemplate.queryForList(arrStation).get(0).get("english_written").toString();
        Node start = new Node(star);
        Node cel = new Node(end);
        String timeBuilt = hourParam + ":" + minuteParam + ":00";
        List<Train> journey = test.brrfAlgorithm(start, cel, timeBuilt, Collections.emptyList(), graph);
        journey = scheduler(journey);

        List<List<Map<String, Object>>> data = test.findTrainsInDatabase(journey, star, end, true);
        trainSet[index] = data;

        greatFour[index][0].setText(data.get(0).get(0).get("dept_time").toString());
        greatFour[index][1].setText(data.get(1).get(journey.size() - 1).get("arr_time").toString());
        greatFour[index][2].setText(deptStationParam);
        greatFour[index][3].setText(arrStationParam);
        if (journey.size() == 1) {
            greatFour[index][4].setText("Bezpośredni");
        } else {
            greatFour[index][4].setText(journey.size() - 1 + " przesiadki");
        }
    }

    public JPanel getResultsApp() {
        return resultsApp;
    }
}
