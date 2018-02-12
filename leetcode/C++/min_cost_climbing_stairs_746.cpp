#include "common.hpp"


// DP
//
// Let dp[i] to be the min cost of climbing to the step i from the ground.
// DP formula: dp[i] = cost[i] + min(dp[i-1] + dp[i-2])

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int min_cost_cur = 0, min_cost_prev = 0, min_cost_prev_prev = 0;
    for (int c : cost) {
      min_cost_cur = c + min(min_cost_prev, min_cost_prev_prev);
      min_cost_prev_prev = min_cost_prev;
      min_cost_prev = min_cost_cur;
    }

    return min(min_cost_prev, min_cost_prev_prev);
  }
};


int main()
{
  Solution sol;
  // vector<int> cost {10, 15, 20};
  vector<int> cost {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << sol.minCostClimbingStairs(cost) << endl;
}
