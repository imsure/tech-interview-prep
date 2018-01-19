package io.imsure.solutions;

import java.util.HashMap;

public class _13 {
    public static class Solution {
        public int romanToInt(String s) {
            if (s.isEmpty()) return 0;

            HashMap<Character, Integer> table = new HashMap<>();
            table.put('I', 1);
            table.put('V', 5);
            table.put('X', 10);
            table.put('L', 50);
            table.put('C', 100);
            table.put('D', 500);
            table.put('M', 1000);

            int ans = 0;
            for (int i = 0; i < s.length() - 1; ++i) {
                int val = table.get(s.charAt(i));
                int next_val = table.get(s.charAt(i+1));
                if (val >= next_val) ans += val;
                else ans -= val;
            }
            ans += table.get(s.charAt(s.length()-1));
            return ans;
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.romanToInt("VIII")); // 8
    }
}
