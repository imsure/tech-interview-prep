#include "common.hpp"

// time:
// space:
class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;

    int r_num = grid.size();
    int c_num = grid[0].size();

    int ones = 0, pairs = 0;

    // scan row by row to determine number of 1's and pairs of 1s row-wise
    for (int i = 0; i < r_num; ++i) {
      for (int j = 0; j < c_num - 1; ++j) {
        if (grid[i][j] == 1) ones += 1;
        if (grid[i][j] == 1 && grid[i][j+1]) pairs += 1;
      }
      if (grid[i][c_num-1] == 1) ones += 1;
    }

    // scan column by column to determine number of pairs of 1s column-wise
    for (int i = 0; i < c_num; ++i) {
      for (int j = 0; j < r_num - 1; ++j) {
        if (grid[j][i] == 1 && grid[j+1][i]) pairs += 1;
      }
    }

    return ones * 4 - 2 * pairs;
  }
};

int main()
{
  vector<vector<int>> grid {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
  Solution sol;
  cout << sol.islandPerimeter(grid) << endl;
}
