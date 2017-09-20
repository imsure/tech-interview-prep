#include "common.hpp"

// time:
// space:

class Solution {
private:
  void convertConf(vector<int>& conf, vector<vector<string>>& confs, int n) {
    string row (n, '.');
    vector<string> board (n, row);

    for (int i = 0; i < n; ++i) {
      board[i][conf[i]] = 'Q';
    }

    confs.push_back(board);
  }

  // recursively find the complete solutions based on partial solution.
  // a parital solution is a board configuration where row 0...r-1 has been configured
  // and the remaining n-r rows need to be configured.
  void solveNQueensRecursive(vector<int>& conf, int n, int r,
                             vector<vector<string>>& confs) {
    if (r == n) { // a complete solution is found
      convertConf(conf, confs, n);
      //for (int i = 0; i < n; ++i) conf[i] = 0; // reset the conf
      return;
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
        solveNQueensRecursive(conf, n, r+1, confs);
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> confs;
    if (n <= 0) return confs;

    // initialize an empty configuration, conf[i] == 0 means
    // row i on the board has been configured. conf[i] == j means
    // column j on row i has been configured with a queen.
    vector<int> conf (n, 0);
    solveNQueensRecursive(conf, n, 0, confs);
    return confs;
  }
};

int main()
{
  Solution sol;
  vector<vector<string>> boards = sol.solveNQueens(0);
  for (auto& board : boards) {
    for (auto& row : board) {
      cout << row << endl;
    }
    cout << endl;
  }
}
