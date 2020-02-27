import java.util.Scanner;

public class Main {
    public static int[][] hFlip(int[][] n) {
        int[][] output = new int[2][2];
        output[0][0] = n[1][0];
        output[0][1] = n[1][1];
        output[1][0] = n[0][0];
        output[1][1] = n[0][1];
        
        return output;
    }
    
    public static int[][] vFlip(int[][] n) {
        int[][] output = new int[2][2];
        output[0][0] = n[0][1];
        output[0][1] = n[0][0];
        output[1][0] = n[1][1];
        output[1][1] = n[1][0];
        
        
        return output;
    }
    
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String flips = input.next();
        int[][] grid = new int[2][2];
        grid[0][0] = 1;
        grid[0][1] = 2;
        grid[1][0] = 3;
        grid[1][1] = 4;
        
        for (int i = 0; i < flips.length(); i++) {
            if (flips.charAt(i) == 'H') {
                grid = hFlip(grid);
            } else {
                grid = vFlip(grid);
            }
        }
        
        System.out.println(grid[0][0] + " " + grid[0][1]);
        System.out.println(grid[1][0] + " " + grid[1][1]);
    }
}