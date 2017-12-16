#include "common.hpp"

// time:
// space:

class Solution {
private:
  void dfs(vector<vector<int>>& grid, int r, int c, int& area) {
    int nr = grid.size();
    int nc = grid[0].size();

    ++area;
    grid[r][c] = 0;
    if (r - 1 >= 0 && grid[r-1][c] == 1) dfs(grid, r - 1, c, area);
    if (r + 1 < nr && grid[r+1][c] == 1) dfs(grid, r + 1, c, area);
    if (c - 1 >= 0 && grid[r][c-1] == 1) dfs(grid, r, c - 1, area);
    if (c + 1 < nc && grid[r][c+1] == 1) dfs(grid, r, c + 1, area);
  }

public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int max_area = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == 1) {
          int cur_area = 0;
          dfs(grid, r, c, cur_area);
          max_area = max(max_area, cur_area);
        }
      }
    }

    return max_area;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
  cout << sol.maxAreaOfIsland(grid) << endl;
}
