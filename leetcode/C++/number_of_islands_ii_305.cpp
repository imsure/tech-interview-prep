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


// Union Find

class UnionFind {
public:
  UnionFind(int N) {
    nodes = new vector<int>(N, -1);
  }

  // returns the parent of 'node'
  int find(int node) {
    if ((*nodes)[node] != node) return find((*nodes)[node]);
    else return node;
  }

  // union 'node1' and 'node2'
  void Union(int node1, int node2) {
    int parent1 = find(node1);
    int parent2 = find(node2);
    nodes->at(parent2) = parent1;
  }

  void setRoot(int node) {
    nodes->at(node) = node;
  }

private:
  vector<int>* nodes;
};

// Union Find with path compression and rank

class UnionFind2 {
public:
  UnionFind2(int N) {
    nodes = new vector<int>(N, -1);
    rank = new vector<int>(N, 0);
  }

  // returns the parent of 'node'
  int find(int node) {
    if ((*nodes)[node] != node) (*nodes)[node] = find((*nodes)[node]);
    return (*nodes)[node];
  }

  // union 'node1' and 'node2'
  void Union(int node1, int node2) {
    int parent1 = find(node1);
    int parent2 = find(node2);
    if (rank->at(parent1) > rank->at(parent2)) nodes->at(parent2) = parent1;
    else if (rank->at(parent2) > rank->at(parent1)) nodes->at(parent1) = parent2;
    else {
      nodes->at(parent1) = parent2;
      rank->at(parent2) += 1;
    }
  }

  void setRoot(int node) {
    nodes->at(node) = node;
  }

private:
  vector<int>* nodes;
  vector<int>* rank;
};

class Solution3 {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    int island_count = 0;
    vector<vector<char>> grid (m, vector<char>(n, '0'));
    UnionFind2 uf (m * n);
    for (auto& pos : positions) {
      int r = pos.first;
      int c = pos.second;
      grid[r][c] = '1';
      // check pos's neighbors to see if they are in the existing islands or not
      unordered_map<int, pair<int, int>> r2p;
      if (r - 1 >= 0 && grid[r-1][c] == '1') r2p[uf.find((r-1) * n + c)] = {r-1, c};
      if (r + 1 < m && grid[r+1][c] == '1') r2p[uf.find((r+1) * n + c)] = {r+1, c};
      if (c - 1 >= 0 && grid[r][c-1] == '1') r2p[uf.find(r * n + (c-1))] = {r, c-1};
      if (c + 1 < n && grid[r][c+1] == '1') r2p[uf.find(r * n + (c+1))] = {r, c+1};

      int root = r * n + c;
      uf.setRoot(root);
      if (!r2p.empty()) {
        for (auto& kv : r2p) {
          auto p = kv.second;
          uf.Union(root, p.first * n + p.second);
        }
        island_count -= (r2p.size() - 1);
      } else {
        ++island_count;
      }
      ans.push_back(island_count);
    }

    return ans;
  }
};


int main()
{
  Solution3 sol;
  // vector<pair<int, int>> pos {{0,0}, {0,1}, {1,2}, {2,1}}; // 1,1,2,3
  vector<pair<int, int>> pos {{0,1}, {1,0}, {1,2}, {2,1}, {1,1}}; // 1,2,3,4,1
  // vector<pair<int, int>> pos {{0,1}, {1,2}, {2,1}, {1,0}, {0,2}, {0,0}, {1,1}}; // 1,2,3,4,3,2,1
  auto res = sol.numIslands2(3, 3, pos);
  for (int r : res) cout << r << endl;
}
