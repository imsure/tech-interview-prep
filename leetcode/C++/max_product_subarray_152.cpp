#include "common.hpp"

// time: O(n)
// space: O(1)
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    int product = 1;
    int max_product1 = numeric_limits<int>::min();

    for (int i = 0; i < len; ++i) {
      if (nums[i] == 0) {
        max_product1 = max(max_product1, 0);
        product = 1;
      } else {
        product *= nums[i];
        max_product1 = max(max_product1, product);
        max_product1 = max(max_product1, nums[i]);
      }
    }

    int max_product2 = numeric_limits<int>::min();
    product = 1;
    for (int i = len - 1; i >= 0; --i) {
      if (nums[i] == 0) {
        max_product2 = max(max_product2, 0);
        product = 1;
      } else {
        product *= nums[i];
        max_product2 = max(max_product2, product);
        max_product2 = max(max_product2, nums[i]);
      }
    }

    return max(max_product1, max_product2);
  }
};

// credit: https://discuss.leetcode.com/topic/6491/share-my-c-solution-maybe-is-the-simplest-solution
//
// similar with my original approach, but with only once scan of array.
//
// idea: compute products from the front and end of the array
// at the same time and update max product along the way, at the
// end will reach the global optimal solution.

// From DP point of view, at any position within the array, the max subarray product is the
// maximum among the current recorded max value, the maximum computed forward and maximum value
// computed backward.
class Solution2 {
public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    int front_prod = 1, back_prod = 1;
    int max_product = numeric_limits<int>::min();

    for (int i = 0; i < len; ++i) {
      front_prod *= nums[i];
      back_prod *= nums[len - i - 1];
      max_product = max(max_product, max(front_prod, back_prod));

      // here's a tricky part: since any numbers times zero is zero, we need a reset here
      front_prod = front_prod == 0 ? 1 : front_prod;
      back_prod = back_prod == 0 ? 1 : back_prod;
    }

    return max_product;
  }
};

// credit: https://www.youtube.com/watch?v=AtzfZHb35YI
// the idea is that during array traversal, we keep track of the min and max
// product we've seen so far, and the maximum subarray product is the maximum between
// max product we've seen so far and the max product recorded previous to this point.
class Solution3 {
public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;

    int max_product = nums[0];
    int curr_min = nums[0];
    int curr_max = nums[0];
    int next_max, next_min;
    for (int i = 1; i < len; ++i) {
      next_max = curr_max * nums[i];
      next_min = curr_min * nums[i];
      // minimum to current is the min of (current value nums[i], nums[i] * curr_max, nums[i] * curr_min)
      curr_min = min(nums[i], min(next_max, next_min));
      // maximum to current is the max of (current value nums[i], nums[i] * curr_max, nums[i] * curr_min)
      curr_max = max(nums[i], max(next_max, next_min));
      max_product = max(max_product, curr_max);
    }

    return max_product;
  }
};

int main()
{
  Solution3 sol;
  vector<int> nums {2,3,-2,4};
  cout << sol.maxProduct(nums) << endl;

  vector<int> nums2 {2,0,3,-2,4,-1};
  cout << sol.maxProduct(nums2) << endl;

  vector<int> nums3 {3,-2,4};
  cout << sol.maxProduct(nums3) << endl;

  vector<int> nums4 {2,-5,-2,-4,3};
  cout << sol.maxProduct(nums4) << endl;
}
