import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int a3 = input.nextInt() * 3;
        int a2 = input.nextInt() * 2;
        int a = input.nextInt();
        int b3 = input.nextInt() * 3;
        int b2 = input.nextInt() * 2;
        int b = input.nextInt();
        
        int totalB = b3 + b2 + b;
        int totalA = a3 + a2 + a;
        
        if (totalA > totalB) {
            System.out.println("A");
        } else if (totalB > totalA) {
            System.out.println("B");
        } else {
            System.out.println("T");
        }
    }
}