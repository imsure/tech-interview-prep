#include "common.hpp"

// Dynamic Programming:
//

// time: O(n)
// space: O(1)

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int len = costs.size();
    if (len == 0) return 0;

    int last_r_cost = costs[0][0];
    int last_b_cost = costs[0][1];
    int last_g_cost = costs[0][2];

    int cur_r_cost, cur_b_cost, cur_g_cost;
    for (int i = 1; i < len; ++i) {
      cur_r_cost = costs[i][0] + min(last_g_cost, last_b_cost);
      cur_b_cost = costs[i][1] + min(last_r_cost, last_g_cost);
      cur_g_cost = costs[i][2] + min(last_r_cost, last_b_cost);
      last_r_cost = cur_r_cost;
      last_b_cost = cur_b_cost;
      last_g_cost = cur_g_cost;
    }

    int min_cost = min(last_r_cost, min(last_b_cost, last_g_cost));
    return min_cost;
  }
};


// directly update cost in-place

class Solution2 {
public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;

    for (int i = 1; i < n; ++i) {
      costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
      costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
      costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
    }

    return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
  }
};

int main()
{
  Solution sol;
  vector<int> nums {};
}
