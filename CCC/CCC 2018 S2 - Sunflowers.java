import java.util.Scanner;

public class Main {
    public static int[][] rotateCW(int[][] matrix) {
        int length = matrix[0].length;
        int[][] newMatrix = new int[length][length];
        
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                newMatrix[i][j] = matrix[length - j - 1][i];
            }
        }
        
        return newMatrix;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[][] heights = new int[N][N];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                heights[i][j] = scan.nextInt();
            }
        }
        
        if (heights[0][0] < heights[0][1] && heights[0][0] < heights[1][0]) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(heights[i][j] + " ");
                }
                System.out.printf("\n");
            }
        } else {
            boolean cw90 = false;
            boolean r180 = false;
            boolean ccw90 = false;
            
            if (heights[0][0] > heights[0][1] && heights[0][0] < heights[1][0]) {
                cw90 = true;
            }
            
            if (heights[0][0] > heights[0][1] && heights[0][0] > heights[1][0]) {
                r180 = true;
            }
            
            if (heights[0][0] < heights[0][1] && heights[0][0] > heights[1][0]) {
                ccw90 = true;
            }
            
            if (ccw90) {
                heights = rotateCW(heights);
            } else if (r180) {
                heights = rotateCW(heights);
                heights = rotateCW(heights);
            } else if (cw90) {
                heights = rotateCW(heights);
                heights = rotateCW(heights);
                heights = rotateCW(heights);
            }
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(heights[i][j] + " ");
                }
                System.out.printf("\n");
            }
        }
        
        
    } 
}