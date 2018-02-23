#include "common.hpp"


// Wrong attemp

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int len = nums.size();
    if (len <= 2) return -1;

    for (int i = 0; i < len; ++i) nums[i] = abs(nums[i]);

    int lsum = nums[0], rsum = nums[len-1];
    int lo = 1, hi = len - 2;
    while (lo < hi) {
      // cout << lsum << ',' << rsum << endl;
      if (lsum < rsum) {
        lsum += nums[lo];
        ++lo;
      } else if (lsum > rsum) {
        rsum += nums[hi];
        --hi;
      } else {
        lsum += nums[lo];
        rsum += nums[hi];
        ++lo;
        --hi;
      }
    }

    if (lsum == rsum && lo == hi) return lo;
    return -1;
  }
};


class Solution2 {
public:
  int pivotIndex(vector<int>& nums) {
    int len = nums.size();
    if (!len) return -1;

    int lsum = 0, rsum = 0;
    vector<int> prefix_sum (len, 0);
    vector<int> suffix_sum (len, 0);

    for (int i = 0; i < len; ++i) {
      lsum += nums[i];
      rsum += nums[len - i - 1];
      prefix_sum[i] = lsum;
      suffix_sum[len - i - 1] = rsum;
    }

    // check the left-most edge case first
    if (suffix_sum[1] == 0) return 0;

    // find the left-most pivot index
    for (int i = 0; i < len - 2; ++i) {
      if (prefix_sum[i] == suffix_sum[i+2]) return i + 1;
    }

    // final edge case check
    if (prefix_sum[len-2] == 0) return len - 1;

    return -1;
  }
};


int main()
{
  Solution2 sol;
  // vector<int> nums {1, 7, 3, 6, 5, 6};  // 3
  // vector<int> nums {1, 2, 3};  // -1
  // vector<int> nums {-1, -1, -1, -1, -1, 0};  // 2
  // vector<int> nums {-1, -1, -1, -1, 0, 1};  // 1
  vector<int> nums {-1, -1, -1, 0, 1, 1};  // 0
  cout << sol.pivotIndex(nums) << endl;
}
