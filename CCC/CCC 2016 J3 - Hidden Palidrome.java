import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList palinLengths = new ArrayList();
        Scanner input = new Scanner(System.in);
        String palindrome = input.next();
        
        int startIndex = 0;
        int endIndex = 0;
        int currentLargest = 0;
        
        while (startIndex != palindrome.length() && endIndex != palindrome.length()) {
            int testLength = endIndex - startIndex + 1;
            int tracker = 0;
            boolean foundPalin = false;
            
            int accessEnd = endIndex;
            int accessStart = startIndex;
            while (tracker <= Math.round(testLength / 2)) {
                if (palindrome.charAt(accessStart) == palindrome.charAt(accessEnd)) {
                    accessStart++;
                    accessEnd--;
                    tracker++;
                    
                    if (tracker * 2 >= testLength) {
                        foundPalin = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            
            if (foundPalin) {
                palinLengths.add(testLength);
            }
            
            foundPalin = false;
            
            if (endIndex == palindrome.length() - 1) {
                startIndex++;
                endIndex = startIndex;
            } else {
                endIndex++;
            }
        }
        
        for (int i = 0; i < palinLengths.size(); i++) {
            int nextValue = (int) palinLengths.get(i);
            if (currentLargest < nextValue) {
                currentLargest = nextValue;
            }
        }
        
        System.out.println(currentLargest);
    }
}