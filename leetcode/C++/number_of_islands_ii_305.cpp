#include "common.hpp"

// Brute force, reuse code of problem 200.
// TLE

class Solution {
private:
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

public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    vector<vector<char>> grid (m, vector<char>(n, '0'));
    for (auto pos : positions) {
      grid[pos.first][pos.second] = '1';
      ans.push_back(numIslands(grid));
    }

    return ans;
  }
};


// Store <row_index, col_index> : island_ID as a map. For each new position:
// - if none of its neighbors is in the map, then it is a new island;
// - if some of its neighbors are in the map:
//   * if they belong to one island, then no new island is found, just add
//     this new position into the existing island it belongs to.
//   * if they belong to more than 1 island, then these islands need to be merged
//     due to they now share a common neighbor (the new position), this is the most
//     time consuming part coz we have to scan the entire map to update!

// Passed with Runtime: 1819 ms

class Solution2 {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    vector<vector<char>> grid (m, vector<char>(n, '0'));
    map<pair<int, int>, int> lands; // (row index, col index) for each land : island ID
    int num_islands = 0;
    int island_id = 0;
    for (auto pos : positions) {
      int r = pos.first;
      int c = pos.second;
      grid[r][c] = '1';
      // check pos's neighbors to see if they are in the existing islands or not
      set<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && lands.count({r-1, c})) overlap.insert(lands[{r-1, c}]);
      if (r + 1 < m && lands.count({r+1, c})) overlap.insert(lands[{r+1, c}]);
      if (c - 1 >= 0 && lands.count({r, c-1})) overlap.insert(lands[{r, c-1}]);
      if (c + 1 < n && lands.count({r, c+1})) overlap.insert(lands[{r, c+1}]);

      if (overlap.empty()) {
        ++num_islands;
        lands[{r, c}] = island_id++;
      } else if (overlap.size() == 1) {
        auto it = overlap.begin();
        lands[{r, c}] = *it;
      } else { // merge
        auto it = overlap.begin();
        int root_id = *it;
        for (auto& kv : lands) { // update island id
          if (overlap.count(kv.second)) kv.second = root_id;
        }
        lands[{r, c}] = root_id;
        num_islands -= (overlap.size() - 1);
      }

      ans.push_back(num_islands);
    }

    return ans;
  }
};


int main()
{
  Solution2 sol;
  // vector<pair<int, int>> pos {{0,0}, {0,1}, {1,2}, {2,1}};
  vector<pair<int, int>> pos {{0,1}, {1,0}, {1,2}, {2,1}, {1,1}};
  auto res = sol.numIslands2(3, 3, pos);
  for (int r : res) cout << r << endl;
}
