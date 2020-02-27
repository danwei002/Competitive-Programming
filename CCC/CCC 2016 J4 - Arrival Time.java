import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String startTime = input.nextLine();
        int hour = Character.getNumericValue(startTime.charAt(0)) * 10 + Character.getNumericValue(startTime.charAt(1));
        int min = Character.getNumericValue(startTime.charAt(3)) * 10 + Character.getNumericValue(startTime.charAt(4));
        
        double counter = 0.0;
        while (counter < 120) {
            if ((hour >= 7 && hour < 10) || (hour >= 15 && hour < 19)) {
                counter += 0.5;
            } else {
                counter++;
            }
            if (min == 59) {
                if (hour == 23) {
                    hour = 0;
                    min = 0;
                } else {
                    hour++;
                    min = 0;
                }
            } else {
                min++;
            }
        }
        
        if (hour < 10) {
            if (min < 10) {
                System.out.println("0" + hour + ":" + "0" + min);
            } else {
                System.out.println("0" + hour + ":" + min);
            }
        } else {
            if (min < 10) {
                System.out.println(hour + ":" + "0" + min);
            } else {
                System.out.println(hour + ":" + min);
            }
        }
    }
}