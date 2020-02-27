import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String game1 = input.next();
        String game2 = input.next();
        String game3 = input.next();
        String game4 = input.next();
        String game5 = input.next();
        String game6 = input.next();
        
        int gamesWon = 0;
        if (game1.equals("W")) {
            gamesWon++;                 
        }
        
        if (game2.equals("W")) {
            gamesWon++;                 
        }
        
        if (game3.equals("W")) {
            gamesWon++;                 
        }
        
        if (game4.equals("W")) {
            gamesWon++;                 
        }
        
        if (game5.equals("W")) {
            gamesWon++;                 
        }
        
        if (game6.equals("W")) {
            gamesWon++;                 
        }
        
        if (gamesWon == 0) {
            System.out.println(-1);
        } else if (gamesWon >= 5) {
            System.out.println(1);
        } else if (gamesWon >= 3) {
            System.out.println(2);
        } else {
            System.out.println(3);
        }
    }
}