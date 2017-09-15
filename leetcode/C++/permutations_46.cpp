#include "common.hpp"

// The permutations for A[1...n] contains:
// - A[1] + permutations for A[1...n] - A[1]
// - A[2] + permutations for A[1...n] - A[2]
// - ......
// - A[n] + permutations for A[1...n] - A[n]

// time:
// space:

class Solution {
private:
  void _permute(vector<int>& nums, int pos, vector<vector<int>>& res) {
    if (pos == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      std::swap(nums[pos], nums[i]);
      _permute(nums, pos+1, res);
      std::swap(nums[pos], nums[i]);
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;

    _permute(nums, 0, res);
    return res;
  }
};

int main()
{
  vector<int> nums {1,2,3};
  Solution sol;
  vector<vector<int>> ps = sol.permute(nums);
  for (auto& p : ps) {
    for (auto i : p) {
      cout << i << ',';
    }
    cout << '\n';
  }
}
