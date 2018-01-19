package io.imsure.solutions;

public class _12 {
    public static class Solution {
        public String intToRoman(int num) {
            StringBuilder roman = new StringBuilder();

            while (num >= 1000) { // [1000,]
                roman.append('M');
                num -= 1000;
            }

            if (num >= 900) { // [900, 1000)
                roman.append("CM");
                num -= 900;
            }

            if (num >= 500) { // [500, 900)
                roman.append('D');
                num -= 500;
            }

            if (num >= 400) { // [400, 500)
                roman.append("CD");
                num -= 400;
            }

            while (num >= 100) { // [100, 400)
                roman.append('C');
                num -= 100;
            }

            if (num >= 90) { // [90, 100)
                roman.append("XC");
                num -= 90;
            }

            if (num >= 50) { // [50, 90)
                roman.append('L');
                num -= 50;
            }

            if (num >= 40) { // [40, 50)
                roman.append("XL");
                num -= 40;
            }

            while (num >= 10) { // [10, 40)
                roman.append('X');
                num -= 10;
            }

            if (num >= 9) { // [9, 10)
                roman.append("IX");
                num -= 9;
            }

            if (num >= 5) { // [5, 9)
                roman.append('V');
                num -= 5;
            }

            if (num >= 4) { // [4, 5)
                roman.append("IV");
                num -= 4;
            }

            while (num >= 1) { // [1, 4)
                roman.append('I');
                num -= 1;
            }

            return roman.toString();
        }
    }

    public static class Solution2 {
        public String intToRoman(int num) {
            StringBuilder roman = new StringBuilder();

            String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            int[] vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

            for (int i = 0; i < vals.length; ++i) {
                while (num >= vals[i]) {
                    roman.append(symbols[i]);
                    num -= vals[i];
                }
            }

            return roman.toString();
        }
    }

    public static void main(String[] args) {
        Solution2 sol = new Solution2();
        System.out.println(sol.intToRoman(3999)); // MMMCMXCIX
    }
}
