import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        String ydy = scan.next();
        String tdy = scan.next();
        int count = 0;
        
        for (int i = 0; i < N; i++) {
            if (ydy.charAt(i) == 'C' && tdy.charAt(i) == 'C' && tdy.charAt(i) == ydy.charAt(i)) {
                count++;
            }
        }
        
        System.out.println(count);
    }
}