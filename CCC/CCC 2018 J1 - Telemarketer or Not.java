import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
      Scanner input = new Scanner(System.in);
      int a = input.nextInt();
      int b = input.nextInt();
      int c = input.nextInt();
      int d = input.nextInt();
      
      if (a == 8 || a == 9) {
          if (b == c) {
              if (d == 8 || d == 9) {
                  System.out.println("ignore");
              } else {
                  System.out.println("answer");
              }
          } else {
              System.out.println("answer");
          }
      } else {
          System.out.println("answer");
      }
    }
}