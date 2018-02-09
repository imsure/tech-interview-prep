#include "common.hpp"


class Solution {
private:
  bool checkDiagnal(int row, int col, int M, int N, vector<vector<int>>& matrix) {
    int val = matrix[row++][col++];
    while (row < M && col < N) {
      if (matrix[row++][col++] != val) return false;
    }

    return true;
  }

public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int M = matrix.size(); // # of rows
    int N = matrix[0].size(); // # of columns

    int row = 0, col = 0;
    for (; row < M; ++row) {
      if (!checkDiagnal(row, col, M, N, matrix)) return false;
    }

    row = 0;
    for (; col < N; ++col) {
      if (!checkDiagnal(row, col, M, N, matrix)) return false;
    }

    return true;
  }
};


int main()
{
  vector<vector<int>> matrix = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
  Solution sol;
  cout << sol.isToeplitzMatrix(matrix) << endl;
}
