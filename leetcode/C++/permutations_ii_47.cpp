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
  void _permute(vector<int> nums, int pos, vector<vector<int>>& res) {
    if (pos == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      if (i != pos && nums[i] == nums[pos]) continue;

      std::swap(nums[pos], nums[i]);
      _permute(nums, pos+1, res);
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;

    std::sort(nums.begin(), nums.end());
    _permute(nums, 0, res);
    return res;
  }
};


class Solution2 {
private:
  void _permute(vector<int>& nums, int pos, unordered_set<int> visited,
                vector<vector<int>>& res) {
    if (pos == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      if (visited.count(nums[i])) continue;

      std::swap(nums[pos], nums[i]);
      unordered_set<int> visited_next;
      _permute(nums, pos+1, visited_next, res);
      std::swap(nums[pos], nums[i]);

      visited.insert(nums[i]);
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;

    unordered_set<int> visited;
    std::sort(nums.begin(), nums.end());
    _permute(nums, 0, visited, res);
    return res;
  }
};


int main()
{
  vector<int> nums {2,2,1,1};
  Solution2 sol;
  vector<vector<int>> ps = sol.permuteUnique(nums);
  for (auto& p : ps) {
    for (auto i : p) {
      cout << i << ',';
    }
    cout << '\n';
  }
}
