#include "common.hpp"


// DP
//
// Let dp[i] to be the number of ways to climb to the top from step i.
// DP formula: dp[i] = dp[i+1] + dp[i+2]

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int dp2 = 1, dp1 = 2;
    int dp;

    for (int i = n - 2; i > 0; --i) {
      dp = dp1 + dp2;
      dp2 = dp1;
      dp1 = dp;
    }

    return dp;
  }
};


int main()
{
  Solution sol;
  cout << sol.climbStairs(2) << endl; // 2
  cout << sol.climbStairs(3) << endl; // 3
}
