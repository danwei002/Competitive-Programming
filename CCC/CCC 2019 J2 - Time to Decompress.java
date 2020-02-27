import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int L = input.nextInt();
        int repArr[] = new int[L];
        String symArr[] = new String[L];
        
        for (int i = 0; i < L; i++) {
            repArr[i] = input.nextInt();
            symArr[i] = input.next();
        }
        
        for (int j = 0; j < L; j++) {
            for (int i = 0; i < repArr[j]; i++) {
                System.out.print(symArr[j]);
            }
            System.out.println("");
        }
    }
}