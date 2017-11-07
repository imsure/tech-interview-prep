#include "common.hpp"

// Since the 1st and last houses are neighbors, we can at most rob one of them,
// thus we can break down the problem into two cases in general:
// - rob house 1 to house n-1, ignoring house n;
// - rob house 2 to house n, ignoring house 1;

// either case can be solved by reusing the code for house robber i.

class Solution {
private:
  int robI(vector<int>& nums, int start, int end) {
    int cur_max = 0, prev_max = 0, tmp;

    for (int i = start; i <= end; ++i) {
      tmp = cur_max;
      cur_max = max(nums[i] + prev_max, cur_max);
      prev_max = tmp;
    }

    return cur_max;
  }

public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    return max(robI(nums, 0, n-2), robI(nums, 1, n-1));
  }
};

int main()
{
  Solution sol;
  vector<int> nums {};
}
