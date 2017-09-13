#include "common.hpp"

// Dynamic Programming:
// at house k, max_money(k) = max(nums[k] + max_money(k-2), max_money(k-1))

// time: O(n)
// space: O(1)

class Solution {
public:
  int rob(vector<int>& nums) {
    int cur_max = 0, prev_max = 0, tmp;

    for (int n : nums) {
      tmp = cur_max;
      cur_max = max(n + prev_max, cur_max);
      prev_max = tmp;
    }

    return cur_max;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {};
}
