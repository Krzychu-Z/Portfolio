package brrf;


import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Utilities {

    private Utilities() {
        throw new IllegalStateException("Utility class");
    }

    // ------ e.g: ARTUS (88110) -> ^ARTUS\s\(8811.*$ -------
    public static String nameRegexBuilder(String nameParam, String carrier) {
        String nameHandler;
        if (carrier.equals("IC") || carrier.equals("TLK")) {
            nameHandler = nameParam.substring(0, nameParam.length() - 2);

            for (int i = 0; i < nameHandler.length(); i++ ) {
                if (nameHandler.charAt(i) == '(') {
                    nameHandler = nameHandler.substring(0, i - 1) + "\\s\\" + nameHandler.substring(i);

                    break;
                }
            }

            return " ~ '^" + nameHandler + ".*$'";
        } else {
            nameHandler = nameParam;
            return " = '" + nameHandler + "'";
        }
    }

    // --------- Checks if any element of both lists is in common --------
    public static boolean matchAny(List<String> one, List<String> two) {
        boolean findAny = false;
        for (String element : one) {
            if (two.contains(element)) {
                findAny = true;
                break;
            }
        }
        return findAny;
    }

    // --------- Removes duplicates and divides trains into travel schedules ----------
    public static List<Train> scheduler(List<Train> mess) {
        List<Train> scheduleHolder = new ArrayList<>(mess);

        for (int i = 1; i < scheduleHolder.size(); i++) {
            if (scheduleHolder.get(i).getRegex().equals(scheduleHolder.get(i - 1).getRegex())) {
                scheduleHolder.remove(scheduleHolder.get(i));
            }
        }

        return scheduleHolder;
    }

    public static List<List<Map<String, Object>>> scheduler2 (List<List<Map<String, Object>>> mess) {
        List<Map<String, Object>> scheduleHolder1 = mess.get(0);
        List<Map<String, Object>> scheduleHolder2 = mess.get(1);

        String departureTime;
        double distance;
        double distanceSum;
        String platform;
        String track;

        for (int i = 0; i < scheduleHolder1.size() - 1; i++) {
            if (scheduleHolder1.get(i).get("name").toString().equals(scheduleHolder1.get(i + 1).get("name").toString())) {
                departureTime = scheduleHolder1.get(i).get("dept_time").toString();
                scheduleHolder1.get(i+1).put("dept_time", departureTime);
                distance = Double.valueOf(scheduleHolder2.get(i).get("kilometers").toString()) - Double.valueOf(scheduleHolder1.get(i).get("kilometers").toString());
                distanceSum = Double.valueOf(scheduleHolder2.get(i+1).get("kilometers").toString()) + distance;
                scheduleHolder2.get(i+1).put("kilometers", String.valueOf(distanceSum));
                platform = scheduleHolder1.get(i).get("platform").toString();
                track = scheduleHolder1.get(i).get("track").toString();
                scheduleHolder1.get(i+1).put("platform", platform);
                scheduleHolder1.get(i+1).put("track", track);

                scheduleHolder1.remove(i);
                scheduleHolder2.remove(i);
            }
        }

        List<List<Map<String, Object>>> data = new ArrayList<>();
        data.add(scheduleHolder1);
        data.add(scheduleHolder2);

        return data;
    }

}
