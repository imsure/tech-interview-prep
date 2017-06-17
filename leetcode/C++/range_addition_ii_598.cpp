#include "common.hpp"

// time:
// space:
class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int min_a = m, min_b = n;
    for (const auto& op : ops) {
      min_a = min(min_a, op[0]);
      min_b = min(min_b, op[1]);
    }

    return min_a * min_b;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> ops {{2,2}, {3,3}};
  cout << sol.maxCount(3, 3, ops) << endl;
}
