#include "common.hpp"

// time:
// space:
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int ones_count = 0;
    int max_count = 0;
    int prev_num = nums[0];
    for (const int num : nums) {
      if (num == 1 && num == prev_num) {
        ++ones_count;
      } else {
        if (num == 0) {
          max_count = max(max_count, ones_count);
          ones_count = 0;
        } else {
          ones_count = 1;
        }
        prev_num = num;
      }
    }
    return max(max_count, ones_count);
  }
};

int main()
{
  vector<int> nums {1,1,0,1,1,1};
  Solution sol;
  cout << sol.findMaxConsecutiveOnes(nums) << endl;
}
