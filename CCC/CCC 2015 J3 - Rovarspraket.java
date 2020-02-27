import java.util.Scanner;

public class Main {
    public static String insert(String x, String addOn, int index) {
        String frontPart = x.substring(0, index);
        String backPart = x.substring(index, x.length());
        
        String outputStr = frontPart + addOn + backPart;
        return outputStr;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String engWord = input.next();
        char[] alphaArray = new char[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                                        't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int aIndex = 0;
        int eIndex = 4;
        int iIndex = 8;
        int oIndex = 14;
        int uIndex = 20;
        
        int index = 0;
        String result = "";
        while (index < engWord.length()) {
            if (engWord.charAt(index) != 'a' && engWord.charAt(index) != 'e' && engWord.charAt(index) != 'i' && engWord.charAt(index) != 'o' 
                && engWord.charAt(index) != 'u') {
                int findIndex = 0;
                for (int i = 0; i < alphaArray.length; i++) {
                    if (engWord.charAt(index) == alphaArray[i]) {
                        findIndex = i;
                        break;
                    }
                }
                
                char addOnChar = engWord.charAt(index);
                String addOn = Character.toString(addOnChar);
                
                if (findIndex < 4) {
                    if (findIndex - aIndex > eIndex - findIndex) {
                        addOn = addOn + alphaArray[eIndex];
                    } else if (findIndex - aIndex < eIndex - findIndex) {
                        addOn = addOn + alphaArray[aIndex];
                    } else {
                        addOn = addOn + alphaArray[aIndex];
                    }
                } else if (findIndex > eIndex && findIndex < iIndex) {
                    if (findIndex - eIndex > iIndex - findIndex) {
                        addOn = addOn + alphaArray[iIndex];
                    } else if (findIndex - eIndex < iIndex - findIndex) {
                        addOn = addOn + alphaArray[eIndex];
                    } else {
                        addOn = addOn + alphaArray[eIndex];
                    }
                } else if (findIndex > iIndex && findIndex < oIndex) {
                    if (findIndex - iIndex > oIndex - findIndex) {
                        addOn = addOn + alphaArray[oIndex];
                    } else if (findIndex - iIndex < oIndex - findIndex) {
                        addOn = addOn + alphaArray[iIndex];
                    } else {
                        addOn = addOn + alphaArray[iIndex];
                    }
                } else if (findIndex > oIndex && findIndex < uIndex) {
                    if (findIndex - oIndex > uIndex - findIndex) {
                        addOn = addOn + alphaArray[uIndex];
                    } else if (findIndex - oIndex < uIndex - findIndex) {
                        addOn = addOn + alphaArray[oIndex];
                    } else {
                        addOn = addOn + alphaArray[oIndex];
                    }
                } else {
                    addOn = addOn + alphaArray[uIndex];
                }
                
                if (findIndex + 1 != 4 && findIndex + 1 != 8 && findIndex + 1 != 14 && findIndex + 1 != 20) {
                    if (findIndex == 25) {
                        addOn = addOn + 'z';
                    } else {
                        addOn = addOn + alphaArray[findIndex + 1];
                    }
                } else {
                    addOn = addOn + alphaArray[findIndex + 2];
                }
                
                result = result + addOn;
            } else {
                char addOnCharB = engWord.charAt(index);
                result = result + Character.toString(addOnCharB);
            }
            
            index++;
        }
        
        System.out.println(result);
    }
}