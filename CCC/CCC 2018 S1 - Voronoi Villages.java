import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        double[] villages = new double[N];
        
        for (int i = 0; i < N; i++) {
            villages[i] = input.nextDouble();
        }
        
        Arrays.sort(villages);
        
        double[] neighbourhoods = new double[N];
        
        for (int i = 1; i < N - 1; i++) {
            double size = 0;
            size = ((villages[i] - villages[i - 1])/2) + ((villages[i + 1] - villages[i])/2);
            neighbourhoods[i] = size;
        }
        
        Arrays.sort(neighbourhoods);
        
        double leSize = 0;
        for (int i = 0; i < neighbourhoods.length; i++) {
            if (neighbourhoods[i] != 0) {
                leSize = neighbourhoods[i];
                break;
            }
        }
        
        System.out.println(String.format ("%.1f", leSize));
    }
}