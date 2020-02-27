import java.util.*;

public class Main {
    public static String getKey(Map<String, String> map, String value) {
        for (String s : map.keySet()) {
            if (map.get(s).equals(value)) {
                return s;
            }
        }
        return null;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String numStudentsS = input.nextLine();
        int numStudents = Integer.parseInt(numStudentsS);
        Map<String, String> partners = new HashMap<>();
        
        String l1 = input.nextLine();
        String[] strs1 = l1.trim().split("\\s+");
        String l2 = input.nextLine();
        String[] strs2 = l2.trim().split("\\s+");
        
        String students[] = strs1;
        
        for (int i = 0; i < numStudents; i++) {
            partners.put(strs1[i], strs2[i]);
        }
        
        boolean consistent = true;
        for (int i = 0; i < partners.size(); i++) {
            String p1 = partners.get(students[i]);
            String p2 = getKey(partners, students[i]);
            if (!p1.equals(p2) || p1.equals(students[i])) {
                consistent = false;
            }
        }
        
        if (consistent) {
            System.out.println("good");
        } else {
            System.out.println("bad");
        }
    }
}