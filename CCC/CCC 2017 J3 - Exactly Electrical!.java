import java.util.Scanner;

public class Main {
    public static boolean canTravel(int x1, int y1, int x2, int y2, int charge) {
        int distX = x1 - x2;
        int distY = y1 - y2;
        
        if (distX < 0) {
            distX = -distX;
        }
        
        if (distY < 0) {
            distY = -distY;
        }
        
        int totalDist = distX + distY;
        boolean enoughCharge = charge >= totalDist;
        
        if (enoughCharge) {
            if ((totalDist % 2 == 0 && charge % 2 == 0) || (totalDist % 2 != 0 && charge % 2 != 0)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int startX = input.nextInt();
        int startY = input.nextInt();
        int destX = input.nextInt();
        int destY = input.nextInt();
        int charge = input.nextInt();
        
        if (canTravel(startX, startY, destX, destY, charge)) {
            System.out.println("Y");
        } else {
            System.out.println("N");
        }
    }
}