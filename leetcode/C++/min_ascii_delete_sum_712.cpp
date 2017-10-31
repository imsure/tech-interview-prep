#include "common.hpp"

// DP approach: let dp[i][j] be the minimum ascii delete sum for s1 ends at i
// and s2 ends at j. Then we have the following recurrence equation:
//
//             / dp[i-1][j-1] if s1[i] == s2[j]
// dp[i][j] = /
//            \  min (dp[i-1][j] + s1[i], dp[i][j-1] + s2[j])

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // (m+1) * (n+1)
    auto dp_ptr = new vector<vector<int>> (m+1, vector<int>(n+1, 0));
    auto& dp = *dp_ptr;

    int sum = 0;
    // initialize dp table
    for (int i = 1; i <= n; ++i) { // first row (s1 is empty)
      sum += s2[i-1];
      dp[0][i] = sum;
    }

    sum = 0;
    for (int i = 1; i <= m; ++i) { // first column (s2 is empty)
      sum += s1[i-1];
      dp[i][0] = sum;
    }

    // fill the table row-wise
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
      }
    }

    // for (int i = 0; i <= m; ++i) {
    //   for (int j = 0; j <= n; ++j) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    return dp[m][n];
  }
};


int main()
{
  Solution sol;
  cout << sol.minimumDeleteSum("sea", "eat") << endl;
  cout << sol.minimumDeleteSum("delete", "leet") << endl;
}
