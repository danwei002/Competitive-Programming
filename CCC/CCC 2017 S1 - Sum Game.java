import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int days = input.nextInt();
        int[] swiftRuns = new int[days + 1];
        int[] semaRuns = new int[days + 1];
        
        for (int i = 1; i <= days; i++) {
            swiftRuns[i] = input.nextInt();
        }
        
        for (int i = 1; i <= days; i++) {
            semaRuns[i] = input.nextInt();
        }
        

        int swiftSum = 0;
        int semaSum = 0;
        int largest = 0;
        for (int i = 1; i <= days; i++) {
            swiftSum += swiftRuns[i];
            semaSum += semaRuns[i];
            
            if (swiftSum == semaSum) {
               largest = i;
            }
        }
        
        System.out.println(largest);
        
    }
}