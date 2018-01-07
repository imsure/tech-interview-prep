package io.imsure.solutions;

import java.util.HashMap;

public class _359 {
    public static class Logger1 {
        private HashMap<String, Integer> msg2time = new HashMap<>();

        /** Initialize your data structure here. */
        public Logger1() {

        }

        /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
         If this method returns false, the message will not be printed.
         The timestamp is in seconds granularity. */
        public boolean shouldPrintMessage(int timestamp, String message) {
            if (timestamp >= msg2time.getOrDefault(message, 0)) {
                msg2time.put(message, timestamp + 10);
                return true;
            }
            return false;
        }
    }

    public static class Logger2 {
        private HashMap<Long, Integer> hash2time = new HashMap<>();

        /** Initialize your data structure here. */
        public Logger2() {

        }

        private long hash(String s) {
            long val = 5381;
            for (int i = 0; i < s.length(); i++){
                char c = s.charAt(i);
                val = ((val << 5) + val) + c; // val * 33 + c
            }
            return val;
        }

        /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
         If this method returns false, the message will not be printed.
         The timestamp is in seconds granularity. */
        public boolean shouldPrintMessage(int timestamp, String message) {
            if (timestamp >= hash2time.getOrDefault(hash(message), 0)) {
                hash2time.put(hash(message), timestamp + 10);
                return true;
            }
            return false;
        }
    }
}
