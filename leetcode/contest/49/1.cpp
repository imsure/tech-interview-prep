#include "../common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time: O(NlogN)
// space: O(N)

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    int len = nums.size();
    if (len < 1) return 0;

    int res = 1;
    int cur_max = 1;
    int prev = nums[0];

    for (int i = 1; i < len; ++i) {
      if (nums[i] > prev) {
        ++cur_max;
      } else {
        cur_max = 1;
      }
      res = max(cur_max, res);
      prev = nums[i];
    }

    return res;
  }
};


int main()
{
  vector<int> nums {1,3,5,4,7};
  Solution sol;
  cout << sol.findLengthOfLCIS(nums) << endl;
}
