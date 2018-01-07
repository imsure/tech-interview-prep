#include "../common.hpp"

class Solution {
private:
  void backtracking(string start, string target, unordered_set<string>& deadset,
                    int count, int& min_move) {
    if (deadset.count(start)) return;
    if (start == target) {
      min_move = min(min_move, count);
      return;
    }

    for (int i = pos; i < 4; ++i) {
      std::swap(nums[pos], nums[i]);
      _permute(nums, pos+1, res);
      std::swap(nums[pos], nums[i]);
    }
  }

public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadset;
    for (auto s : deadends) deadset.insert(s);

    int min_move = numeric_limits<int>::max();
    backtracking("0000", target, deadset, 0, min_move);
  }
};

int main()
{
  Solution sol;
}
