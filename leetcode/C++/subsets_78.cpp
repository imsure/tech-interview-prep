#include "common.hpp"

// Find all the subsets of A[1...n]:
// - isolate A[1]
// - Find all the subsets of A[2...n] as B
// - Let C = all the subsets in B augmented with A[1]
// - return B and C

// time:
// space:

class Solution {
private:
  void recSubsets(vector<int>& nums, int start, vector<vector<int>>& res) {
    if (start >= nums.size()) {
      res.push_back(vector<int>()); // empty set
      return;
    }

    int isolated_num = nums[start];
    recSubsets(nums, start+1, res);
    int cur_sz = res.size();
    for (int i = 0; i < cur_sz; ++i) {
      vector<int> new_set(res[i]);
      new_set.push_back(isolated_num);
      res.push_back(new_set);
    }
  }

public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    recSubsets(nums, 0, res);
    return res;
  }
};

int main()
{
  vector<int> nums {1,2,3};
  Solution sol;
  vector<vector<int>> res = sol.subsets(nums);
  for (auto& set : res) {
    for (auto i : set) {
      cout << i << ',';
    }
    cout << '\n';
  }
}
