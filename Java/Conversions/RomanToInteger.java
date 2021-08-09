package Conversions;

import java.util.*;

public class RomanToInteger {
    private static Map<Character, Integer> map = new HashMap<Character, Integer>() {
        private static final long serialVersionUID = 87605733047260530L;

        {
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);
        }
    };

    public static int romanToInt(String A) {
        A = A.toUpperCase();
        char prev = ' ';
        int sum = 0;
        int newPrev = 0;

        for(int i = A.length() - 1; i >= 0; i--) {
            char c = A.charAt(i);

            if(prev != ' ') {
                newPrev = map.get(prev) > newPrev ? map.get(prev) : newPrev;
            }

            int currentNum = map.get(c);

            if(currentNum >= newPrev) {
                sum += currentNum;
            }
            else {
                sum -= currentNum;
            }

            prev = c;
        }

        return sum;
    }

    public static void main(String[] args) {
        int sum = romanToInt("MDCCCIV");
        int sum2 = romanToInt("IV");
        int sum3 = romanToInt("VI");
        int sum4 = romanToInt("XIV");

        System.out.println(sum);
        System.out.println(sum2);
        System.out.println(sum3);
        System.out.println(sum4);
    }

}