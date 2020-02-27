import java.util.Scanner;

public class Main {
    public static String getSubstring(String in, int startIndex) {
        String output = "";
        int checkIndex = 0;
        while (true) {
            if (in.charAt(startIndex) == in.charAt(checkIndex)) {
                checkIndex++;
                output += Character.toString(in.charAt(startIndex));
            } else {
                break;
            }
        }
        return output;
    }
    
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        for (int i = 0; i < N; i++) {
            int trackIndex = 0;
            String line = input.next();
            line += "}";
            
            int startIndex = 0;
            int index = 0;
            while (index < line.length()) {
                char startChar = line.charAt(startIndex);

                if (line.charAt(index) != startChar) {
                    System.out.print(index - startIndex + " " + startChar + " ");
                    startIndex = index;
                } else {
                    index++;
                }
            }
            System.out.println("");
        }
    }
}