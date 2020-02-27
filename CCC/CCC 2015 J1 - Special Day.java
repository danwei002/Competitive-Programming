import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int monthNum = input.nextInt();
        int day = input.nextInt();
        
        if (monthNum == 1) {
            System.out.println("Before");
        } else if (monthNum == 2) {
            if (day < 18) {
                System.out.println("Before");
            } else if (day == 18) {
                System.out.println("Special");
            } else {
                System.out.println("After");
            }
        } else {
            System.out.println("After");
        }
    }
}