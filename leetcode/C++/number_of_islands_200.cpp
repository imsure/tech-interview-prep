#include "common.hpp"

// time:
// space:

// BFS

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int ans = 0;
    auto visited_ptr = new vector<vector<bool>>(nr, vector<bool>(nc, false));
    auto& visited = *visited_ptr;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '0' || visited[r][c]) continue;
        queue<pair<int, int>> lands;
        lands.push({r, c});
        visited[r][c] = true;
        while (!lands.empty()) {
          auto rc = lands.front();
          lands.pop();
          if (rc.first - 1 >= 0 && grid[rc.first-1][rc.second] == '1' && !visited[rc.first-1][rc.second]) {
            lands.push({rc.first-1, rc.second});
            visited[rc.first-1][rc.second] = true;
          }
          if (rc.first + 1 < nr && grid[rc.first+1][rc.second] == '1' && !visited[rc.first+1][rc.second]) {
            lands.push({rc.first+1, rc.second});
            visited[rc.first+1][rc.second] = true;
          }
          if (rc.second - 1 >= 0 && grid[rc.first][rc.second-1] == '1' && !visited[rc.first][rc.second-1]) {
            lands.push({rc.first, rc.second-1});
            visited[rc.first][rc.second-1] = true;
          }
          if (rc.second + 1 < nc && grid[rc.first][rc.second+1] == '1' && !visited[rc.first][rc.second+1]) {
            lands.push({rc.first, rc.second+1});
            visited[rc.first][rc.second+1] = true;
          }
        }
        ++ans;
      }
    }

    return ans;
  }
};


// Wrong attemp!

class Solution2 {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int ans = 0;
    auto visited_ptr = new vector<vector<bool>>(nr, vector<bool>(nc, false));
    auto& visited = *visited_ptr;
    int r = 0, c = 0;
    while (r < nr) {
      if (grid[r][c] == '0') {
        if (c + 1 < nc) ++c;
        else {
          ++r; c = 0;
        }
        continue;
      }
      int max_r = 0, max_c = 0;
      queue<pair<int, int>> lands;
      lands.push({r, c});
      visited[r][c] = true;
      while (!lands.empty()) {
        auto rc = lands.front();
        lands.pop();
        max_r = max(max_r, rc.first);
        max_c = max(max_c, rc.second);
        if (rc.first - 1 >= 0 && grid[rc.first-1][rc.second] == '1' && !visited[rc.first-1][rc.second]) {
          lands.push({rc.first-1, rc.second});
          visited[rc.first-1][rc.second] = true;
        }
        if (rc.first + 1 < nr && grid[rc.first+1][rc.second] == '1' && !visited[rc.first+1][rc.second]) {
          lands.push({rc.first+1, rc.second});
          visited[rc.first+1][rc.second] = true;
        }
        if (rc.second - 1 >= 0 && grid[rc.first][rc.second-1] == '1' && !visited[rc.first][rc.second-1]) {
          lands.push({rc.first, rc.second-1});
          visited[rc.first][rc.second-1] = true;
        }
        if (rc.second + 1 < nc && grid[rc.first][rc.second+1] == '1' && !visited[rc.first][rc.second+1]) {
          lands.push({rc.first, rc.second+1});
          visited[rc.first][rc.second+1] = true;
        }
      }
      ++ans;
      if (max_c + 2 < nc) {
        r = max_r;
        c = max_c + 2;
      }
      else {
        r = max_r + 1; c = 0;
      }
      // cout << "r = " << r << ", c = " << c << endl;
    }

    return ans;
  }
};


// DFS

class Solution3 {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int ans = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          dfs(grid, r, c);
          ++ans;
        }
      }
    }

    return ans;
  }
};


int main()
{
  Solution3 sol;
  // vector<vector<char>> grid {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
  vector<vector<char>> grid {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
  cout << sol.numIslands(grid) << endl;
}
