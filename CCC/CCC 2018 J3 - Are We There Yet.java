import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int in1 = scan.nextInt();
        int in2 = scan.nextInt();
        int in3 = scan.nextInt();
        int in4 = scan.nextInt();
        
        System.out.println(0 + " " + in1 + " " + (in1 + in2) + " " + (in1 + in2 + in3) + " " + (in1 + in2 + in3 + in4));
        System.out.println(in1 + " " + 0 + " " + in2 + " " + (in2 + in3) + " " + (in2 + in3 + in4));
        System.out.println((in1 + in2) + " " + in2 + " " + 0 + " " + in3 + " " + (in3 + in4));
        System.out.println((in1 + in2 + in3) + " " + (in2 + in3) + " " + in3 + " " + 0 + " " + in4);
        System.out.println((in1 + in2 + in3 + in4) + " " + (in2 + in3 + in4) + " " + (in3 + in4) + " " + in4 + " " + 0);
    } 
}