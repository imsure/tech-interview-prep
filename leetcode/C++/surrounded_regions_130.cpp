#include "common.hpp"

// DFS
// DFS all 'O's on the board, keep tracking their positions and whether or not
// they are surrounded by 'X'.
// A region of 'O' is surrounded by 'X' iff all boundary cells are surrounded 'X'.
// A boundary cell must fullfill the following requirements:
// - must have 4 neighbors
// - at least one neighbor needs to be 'X'

// stack overflowed

class Solution {
private:
  void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited,
           bool& surroundedByX, vector<int>& regions) {
    int nr = board.size();
    int nc = board[0].size();

    if (r < 0 || c < 0 || r >= nr || c >= nc) {
      surroundedByX = false; return;
    }

    if (visited[r][c] || board[r][c] == 'X') return;

    visited[r][c] = true;
    regions.push_back(r * nc + c);

    dfs(board, r - 1, c, visited, surroundedByX, regions);
    dfs(board, r + 1, c, visited, surroundedByX, regions);
    dfs(board, r, c - 1, visited, surroundedByX, regions);
    dfs(board, r, c + 1, visited, surroundedByX, regions);
  }

public:
  void solve(vector<vector<char>>& board) {
    int nr = board.size();
    if (!nr) return;
    int nc = board[0].size();

    vector<vector<bool>> visited (nr, vector<bool>(nc, false));
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (board[r][c] == 'O' && !visited[r][c]) {
          bool surroundedByX = true;
          vector<int> regions;
          dfs(board, r, c, visited, surroundedByX, regions);
          if (surroundedByX) {
            for (int index : regions) {
              int row = index / nc;
              int col = index % nc;
              board[row][col] = 'X';
            }
          }
        }
      }
    }
  }
};


class Solution2 {
public:
  void solve(vector<vector<char>>& board) {
    int nr = board.size();
    if (!nr) return;
    int nc = board[0].size();

    vector<vector<bool>> visited (nr, vector<bool>(nc, false));
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (board[r][c] == 'O' && !visited[r][c]) {
          queue<pair<int, int>> q;
          vector<pair<int, int>> region;
          bool surrounded = true;
          q.push({r, c});
          region.push_back({r, c});
          visited[r][c] = true;
          while (!q.empty()) {
            auto index = q.front();
            int rindex = index.first;
            int cindex = index.second;
            q.pop();
            if (rindex == 0 || rindex == nr-1 || cindex == 0 || cindex == nc-1) surrounded = false;
            if (rindex - 1 >= 0 && !visited[rindex-1][cindex] && board[rindex-1][cindex] == 'O') {
              q.push({rindex - 1, cindex});
              region.push_back({rindex - 1, cindex});
              visited[rindex-1][cindex] = true;
            }
            if (rindex + 1 < nr && !visited[rindex+1][cindex] && board[rindex+1][cindex] == 'O') {
              q.push({rindex + 1, cindex});
              region.push_back({rindex + 1, cindex});
              visited[rindex+1][cindex] = true;
            }
            if (cindex - 1 >= 0 && !visited[rindex][cindex-1] && board[rindex][cindex-1] == 'O') {
              q.push({rindex, cindex - 1});
              region.push_back({rindex, cindex - 1});
              visited[rindex][cindex-1] = true;
            }
            if (cindex + 1 < nc && !visited[rindex][cindex+1] && board[rindex][cindex+1] == 'O') {
              q.push({rindex, cindex + 1});
              region.push_back({rindex, cindex + 1});
              visited[rindex][cindex+1] = true;
            }
          }
          if (surrounded) {
            for (auto index : region) board[index.first][index.second] = 'X';
          }
        }
      }
    }
  }
};

int main()
{
  Solution2 sol;
  vector<vector<char>> board {{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
  // vector<vector<char>> board {{'O','O','O','O'}, {'O','X','O','O'}, {'O','X','X','O'}, {'O','O','O','O'}};
  sol.solve(board);
  for (auto& row : board) {
    for (char cell : row) cout << cell << '\t';
    cout << '\n';
  }
}

