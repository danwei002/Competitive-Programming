import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numFriends = input.nextInt();
        ArrayList<Integer> friends = new ArrayList<Integer>();
        
        for (int i = 1; i <= numFriends; i++) {
            friends.add(i);
        }
        
        int rounds = input.nextInt();
        int[] removalMultiples = new int[rounds];
        
        for (int i = 0; i < rounds; i++) {
            removalMultiples[i] = input.nextInt();
        }
        
        for (int i = 0; i < rounds; i++) {
            ArrayList<Integer> toBeRemoved = new ArrayList<Integer>();
            int removalIndex = -1;
            while (removalIndex < friends.size()) {
                removalIndex += removalMultiples[i];
                if (removalIndex < friends.size()) {
                    toBeRemoved.add(friends.get(removalIndex));
                }
            }
            
            friends.removeAll(toBeRemoved);
        }
        
        for (int i = 0; i < friends.size(); i++) {
            System.out.println(friends.get(i));
        }
    }
}