import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int s = input.nextInt();
        int k = input.nextInt();
        int sum = s;
        for (int i = 1; i <= k; i++) {
            sum += s * (Math.pow(10, i));
        }
        
        System.out.println(sum);
    }
}