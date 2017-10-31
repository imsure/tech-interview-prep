#include "../common.hpp"

// DP approach: got an memory limit exceeded error...

class Solution {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    int max_len = 0;

    vector<vector<int>> T (m+1, vector<int> (n+1, 0));

    // fill the table row-wise
    for (int i = m-1; i >= 0; --i) {
      for (int j = n-1; j >= 0; --j) {
        if (A[i] == B[j]) {
          if (i == m-1 || j == n-1) T[i][j] = 1 + T[i+1][j+1];
          else if (A[i+1] == B[j+1]) T[i][j] = 1 + T[i+1][j+1];
          else T[i][j] = 1;
        }
        else {
          if (i == m-1 || j == n-1) T[i][j] = 0;
          else if (A[i+1] == B[j] && A[i] == B[j+1]) T[i][j] = max(T[i+1][j], T[i][j+1]);
          else if (A[i+1] == B[j]) T[i][j] = T[i+1][j];
          else if (A[i] == B[j+1]) T[i][j] = T[i][j+1];
          else T[i][j] = 0;
        }

        max_len = max(max_len, T[i][j]);
      }
    }

    // for (int i = 0; i <= m; ++i) {
    //   for (int j = 0; j <= n; ++j) {
    //     cout << T[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    return max_len;
  }
};

// Brute force: time limit exceeded......

class Solution2 {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    int max_len = 0;

    for (int i = 0; i < m; ++i) {
      int p1 = i;
      for (int j = 0; j < n; ++j) {
        if (A[i] != B[j]) continue;

        int p2 = j, cur_len = 0;
        while (p1 < m && p2 < n && A[p1] == B[p2]) { ++p1; ++p2; ++cur_len; }
        p1 = i; // reset p1
        // cout << "p1: " << p1 << ", p2: " << p2 << ", cur len: " << cur_len << endl;
        max_len = max(max_len, cur_len);
      }
    }

    return max_len;
  }
};


// DP approach with space optimized

class Solution3 {
private:
  // A.size >= B.size
  int _findLength(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    int max_len = 0;
    vector<int> table (n+1, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = n; j >= 1; --j) {
        if (B[j-1] == A[i]) table[j] = 1 + table[j-1]; // max len of repeated subarray ends at A[i] and B[j-1]
        else table[j] = 0;
        max_len = max(max_len, table[j]);
      }
    }

    return max_len;
  }

public:
  int findLength(vector<int>& A, vector<int>& B) {
    int max_len;

    if (B.size() <= A.size()) {
      max_len =_findLength(A, B);
    } else {
      max_len =_findLength(B, A);
    }

    return max_len;
  }
};


class Solution4 {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    int max_len = 0;

    auto dp_ptr = new vector<vector<int>>(m+1, vector<int> (n+1, 0));
    auto dp = *dp_ptr;
    // dp[i][j] is the answer to A[0...i) and B(0...j), i.e., the max length of repeated subarray ends at A[i-1] and B[j-1]
    // dp[i][j] = 0 if A[i-1] != B[j-1], otherwise dp[i][j] = 1 + dp[i-1][j-1]
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <=n; ++j) {
        if (A[i-1] != B[j-1]) dp[i][j] = 0;
        else {
          dp[i][j] = 1 + dp[i-1][j-1];
          max_len = max(max_len, dp[i][j]);
        }
      }
    }

    return max_len;
  }
};

int main()
{
  Solution4 sol;
  // vector<int> A {0,1,1,1,1};
  // vector<int> B {1,0,1,0,1};
  vector<int> A {1,2,3,2,1};
  vector<int> B {3,2,1,4,7};
  // vector<int> A {0,0,0,0,0,0,1,0,0,0};
  // vector<int> B {0,0,0,0,0,0,0,1,0,0,0};
  cout << sol.findLength(A, B) << endl;
}
