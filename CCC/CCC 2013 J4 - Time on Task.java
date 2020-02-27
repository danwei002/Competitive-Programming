import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int total = input.nextInt();
        int[] chores = new int[input.nextInt()];
        for (int i = 0; i < chores.length; i++) {
            chores[i] = input.nextInt();
        }
        
        Arrays.sort(chores);
        
        int canDo = 0;
        for (int i = 0; i < chores.length; i++) {
            if (chores[i] <= total) {
                canDo++;
                total -= chores[i];
            }
        }
        
        System.out.println(canDo);
    }
}