import java.util.Scanner;

public class Main {
    
    
    public static boolean primeCheck(int n) {
        if (n < 2) {
            return false;
        }
        if(n == 2 || n == 3) {
            return true;
        }
        
        if(n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        
        long sqrtN = (long)Math.sqrt(n)+1;
        
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n % (i - 1) == 0 || n % (i + 1) == 0) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        
        
        int val;
        for (int i = 0; i < T; i++) {
            val = input.nextInt();
            if (primeCheck(val)) {
                System.out.println(val + " " + val);
            } else {
                int doubleV = val * 2;
                int tracker = 0;
                int num = 3;
                while (tracker < 78498) {
                    if (primeCheck(num)) {
                        if (primeCheck(doubleV - num)) {
                            System.out.println(doubleV - num + " " + num);
                            break;
                        }
                    }
                    num += 2;
                    tracker++;
                }
            }
        }
        
        
    }
}