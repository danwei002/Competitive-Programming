import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String message = input.nextLine();
        
        int numHappy = 0;
        int numSad = 0;
        int index = 0;
        while (index < message.length()) {
            if (message.charAt(index) == ':') {
                if (message.charAt(index + 1) == '-' && message.charAt(index + 2) == ')') {
                    numHappy++;
                } else if (message.charAt(index + 1) == '-' && message.charAt(index + 2) == '(') {
                    numSad++;
                }
            }
            
            index++;
        }
        
        if (numHappy == 0 && numSad == 0) {
            System.out.println("none");
        } else if (numHappy > numSad) {
            System.out.println("happy");
        } else if (numHappy < numSad) {
            System.out.println("sad");
        } else if (numHappy == numSad) {
            System.out.println("unsure");
        }
    }
}