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



// Recursive approach (TLE)
//
// time: O(2^n)

class Solution2 {
private:
  int _climbStairs(int i, int n) {
    if (i > n) return 0;
    if (i == n) return 1;

    return _climbStairs(i+1, n) + _climbStairs(i+2, n);
  }

public:
  int climbStairs(int n) {
    return _climbStairs(0, n);
  }
};


// Recursive approach with memorization
//
// time: O(n)

class Solution3 {
private:
  int _climbStairs(int i, int n, unordered_map<int, int>& table) {
    if (i > n) return 0;
    if (i == n) return 1;

    if (!table.count(i + 1)) table[i+1] = _climbStairs(i+1, n, table);
    if (!table.count(i + 2)) table[i+2] = _climbStairs(i+2, n, table);

    return table[i + 1] + table[i + 2];
  }

public:
  int climbStairs(int n) {
    unordered_map<int, int> table;
    return _climbStairs(0, n, table);
  }
};


int main()
{
  Solution3 sol;
  cout << sol.climbStairs(2) << endl; // 2
  cout << sol.climbStairs(3) << endl; // 3
}
