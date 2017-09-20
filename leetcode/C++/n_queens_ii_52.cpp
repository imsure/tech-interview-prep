#include "common.hpp"

// time:
// space:

class Solution {
private:
  // recursively find the complete solutions based on partial solution.
  // a parital solution is a board configuration where row 0...r-1 has been configured
  // and the remaining n-r rows need to be configured.
  void solveNQueensRecursive(vector<int>& conf, int n, int r, int& total) {
    if (r == n) { // a complete solution is found
      ++total; return;
    }

    // try out every possible value of conf[r]
    for (int j = 0; j < n; ++j) {
      bool legal = true;
      // check if current j is legal given the parital solution
      for (int i = 0; i < r; ++i) {
        if (conf[i] == j || conf[i] == r - i + j || conf[i] == j - (r - i)) {
          legal = false; break;
        }
      }
      if (legal) {
        conf[r] = j;
        solveNQueensRecursive(conf, n, r+1, total);
      }
    }
  }

public:
  int totalNQueens(int n) {
    int total = 0;
    if (n <= 0) return total;

    // initialize an empty configuration, conf[i] == 0 means
    // row i on the board has been configured. conf[i] == j means
    // column j on row i has been configured with a queen.
    vector<int> conf (n, 0);
    solveNQueensRecursive(conf, n, 0, total);
    return total;
  }
};

int main()
{
  Solution sol;
  cout << sol.totalNQueens(1) << endl;
}
