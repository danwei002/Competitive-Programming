import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int hour = 12;
        int minL = 0;
        int minR = 0;
        int minutesToWatch = input.nextInt();
        
        int totalArith = 0;
        
        if (minutesToWatch <= 10000) {
            for (int i = 0; i < minutesToWatch; i++) {
                if (minL == 5 && minR == 9) {
                    minL = 0;
                    minR = 0;
                    if (hour == 12) {
                        hour = 1;
                    } else {
                        hour++;
                    }
                } else {
                    if (minR == 9) {
                        minR = 0;
                        minL++;
                    } else {
                        minR++;
                    }
                }
                
                if (hour >= 10 && hour <= 12) {
                    int hourL = hour / 10;
                    int hourR = hour % 10;
                    
                    if ((minR - minL == minL - hourR) && (minL - hourR == hourR - hourL)) {
                        totalArith++;
                    }
                } else {
                    if (minR - minL == minL - hour) {
                        totalArith++;
                    }
                }
            }
        } else {
            for (int i = 0; i < 720; i++) {
                if (minL == 5 && minR == 9) {
                    minL = 0;
                    minR = 0;
                    if (hour == 12) {
                        hour = 1;
                    } else {
                        hour++;
                    }
                } else {
                    if (minR == 9) {
                        minR = 0;
                        minL++;
                    } else {
                        minR++;
                    }
                }
                
                if (hour >= 10 && hour <= 12) {
                    int hourL = hour / 10;
                    int hourR = hour % 10;
                    
                    if ((minR - minL == minL - hourR) && (minL - hourR == hourR - hourL)) {
                        totalArith++;
                    }
                } else {
                    if (minR - minL == minL - hour) {
                        totalArith++;
                    }
                }
            }
            
            int rep = minutesToWatch / 720;
            totalArith *= rep;
            int rem = minutesToWatch % 720;
            
            for (int i = 0; i < rem; i++) {
                if (minL == 5 && minR == 9) {
                    minL = 0;
                    minR = 0;
                    if (hour == 12) {
                        hour = 1;
                    } else {
                        hour++;
                    }
                } else {
                    if (minR == 9) {
                        minR = 0;
                        minL++;
                    } else {
                        minR++;
                    }
                }
                
                if (hour >= 10 && hour <= 12) {
                    int hourL = hour / 10;
                    int hourR = hour % 10;
                    
                    if ((minR - minL == minL - hourR) && (minL - hourR == hourR - hourL)) {
                        totalArith++;
                    }
                } else {
                    if (minR - minL == minL - hour) {
                        totalArith++;
                    }
                }
            }
        }
        
        System.out.println(totalArith);
    }
}