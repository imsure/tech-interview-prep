package io.imsure.non_contest;

public class BinarySearch {

    // iterative
    public static class Solution1 {
        public int search(int[] nums, int target) {
            int lo = 0, hi = nums.length - 1;
            int mid;

            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (nums[mid] > target) {
                    hi = mid - 1;
                } else if (nums[mid] < target) {
                    lo = mid + 1;
                } else {
                    return mid;
                }
             }

            return -1;
        }
    }

    // recursive
    public static class Solution2 {
        int binarySearch(int[] nums, int target, int lo, int hi) {
            if (lo > hi) {
                return -1;
            }

            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;

            return binarySearch(nums, target, lo, hi);
        }

        public int search(int[] nums, int target) {
           return binarySearch(nums, target, 0, nums.length - 1);
        }
    }

    // linear search
    public static class Solution3 {
        public int search(int[] nums, int target) {
            for (int i = 0; i < nums.length; ++i) {
                if (nums[i] == target) return i;
                if (nums[i] > target) return -1;
            }

            return -1;
        }
    }
}
