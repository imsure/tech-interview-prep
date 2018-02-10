#include "common.hpp"


class Solution {
private:
  bool checkAbove(int& neighbor_count, int& total, vector<vector<int>>& M,
                  int h, int w, int r, int c) {
    if (r - 1 >= 0) {
      neighbor_count++;
      total += M[r-1][c];
      return true;
    }
    return false;
  }

  bool checkBelow(int& neighbor_count, int& total, vector<vector<int>>& M,
                  int h, int w, int r, int c) {
    if (r + 1 < h) {
      neighbor_count++;
      total += M[r+1][c];
      return true;
    }
    return false;
  }

  void checkLeft(int& neighbor_count, int& total, vector<vector<int>>& M,
                 int h, int w, int r, int c) {
    if (c - 1 >= 0) {
      neighbor_count++;
      total += M[r][c-1];
    }
  }

  void checkRight(int& neighbor_count, int& total, vector<vector<int>>& M,
                 int h, int w, int r, int c) {
    if (c + 1 < w) {
      neighbor_count++;
      total += M[r][c+1];
    }
  }

public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int h = M.size();
    int w = M[0].size();

    vector<vector<int>> ret (h, vector<int> (w));

    for (int r = 0; r < h; ++r) {
      for (int c = 0; c < w; ++c) {
        int neighbor_count = 1;
        int total = M[r][c];
        if (checkAbove(neighbor_count, total, M, h, w, r, c)) {
          checkLeft(neighbor_count, total, M, h, w, r-1, c);
          checkRight(neighbor_count, total, M, h, w, r-1, c);
        }
        if (checkBelow(neighbor_count, total, M, h, w, r, c)) {
          checkLeft(neighbor_count, total, M, h, w, r+1, c);
          checkRight(neighbor_count, total, M, h, w, r+1, c);
        }
        checkLeft(neighbor_count, total, M, h, w, r, c);
        checkRight(neighbor_count, total, M, h, w, r, c);
        // cout << "total: " << total << ',' << "count: " << neighbor_count << endl;
        ret[r][c] = total / neighbor_count;
      }
    }

    return ret;
  }
};


int main()
{
  vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
  Solution sol;
  auto M = sol.imageSmoother(matrix);
  for (auto& row : M) {
    for (int v : row) cout << v << ' ';
    cout << '\n';
  }
}
