import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] magicSquare = new int[16];
        
        for (int i = 0; i < magicSquare.length; i++) {
            int num = input.nextInt();
            magicSquare[i] = num;
        }
        
        int row1 = magicSquare[0] + magicSquare[1] + magicSquare[2] + magicSquare[3];
        int row2 = magicSquare[4] + magicSquare[5] + magicSquare[6] + magicSquare[7];
        int row3 = magicSquare[8] + magicSquare[9] + magicSquare[10] + magicSquare[11];
        int row4 = magicSquare[12] + magicSquare[13] + magicSquare[14] + magicSquare[15];
        
        int col1 = magicSquare[0] + magicSquare[4] + magicSquare[8] + magicSquare[12];
        int col2 = magicSquare[1] + magicSquare[5] + magicSquare[9] + magicSquare[13];
        int col3 = magicSquare[2] + magicSquare[6] + magicSquare[10] + magicSquare[14];
        int col4 = magicSquare[3] + magicSquare[7] + magicSquare[11] + magicSquare[15];
        
        if ((row1 == row2) && (row2 == row3)  && (row3 == row4) && (row4 == col1) && (col1 == col2) && (col2 == col3) && (col3 == col4)) {
            System.out.println("magic");
        } else {
            System.out.println("not magic");
        }
    }
}