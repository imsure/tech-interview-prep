#include "common.hpp"

class Solution {
private:
  int findMin(vector<int>& colors, int exclude) {
    int min_cost = numeric_limits<int>::max();
    for (int i = 0; i < colors.size(); ++i) {
      if (i != exclude) min_cost = min(min_cost, colors[i]);
    }

    return min_cost;
  }

public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (!n) return 0;
    int k = costs[0].size();

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        costs[i][j] += findMin(costs[i-1], j);
      }
    }

    return findMin(costs[n-1], k);
  }
};

int main()
{
  Solution sol;
  vector<int> nums {};
}
