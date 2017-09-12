#include "../common.hpp"

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int len = nums.size();
    if (len < 1) return 0;

    unordered_set<int> lcis;
    int i = 1, j = len - 1;
    int max_len = 1, cur_len = 1;
    int l_val = nums[0];

    while (i < j) {
      if (nums[i] < nums[j] && nums[i] > l_val) {
        ++cur_len;
        l_val = nums[i++];
      } else {
        cur_len = 1;
        ++i;
      }
      max_len = max(max_len, cur_len);
    }
  }
};


int main()
{
  vector<int> nums {1,3,5,4,7};
  Solution sol;
  cout << sol.findLengthOfLCIS(nums) << endl;
}
