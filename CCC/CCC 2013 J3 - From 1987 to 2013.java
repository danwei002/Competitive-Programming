import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int year = input.nextInt();
        boolean found = false;
        
        while (!found) {
            year += 1;
            int i = year;
            if (i >= 10000) {
                year = 10234;
                break;
            }
            
            if (i >= 1000) {
                 int thousands = i / 1000;
                i -= thousands * 1000;
                int hundreds = i / 100;
                i -= hundreds * 100;
                int tens = i / 10;
                i -= tens * 10;
                int ones = i;
                
                if (thousands != hundreds && thousands != tens && thousands != ones && hundreds != tens && hundreds != ones && tens != ones) {
                    found = true;
                }
            } else if (i >= 100) {
                int hundreds = i / 100;
                i -= hundreds * 100;
                int tens = i / 10;
                i -= tens * 10;
                int ones = i;
                
                if (hundreds != tens && hundreds != ones && tens != ones) {
                    found = true;
                }
            } else if (i >= 10) {
                int tens = i / 10;
                i -= tens * 10;
                int ones = i;
                
                if (tens != ones) {
                    found = true;
                }
            } else {
                found = true;
            }
        }
        
        System.out.println(year);
    }
}