#include "common.hpp"

// Brute force

class Solution {
private:
  // for each cell, scan both row-wise and column-wise to identify adjacent candies
  void checkBoard(vector<vector<int>>& board, set<pair<int, int>>& crushes,
                  unordered_map<int, set<int>>& group_by_col, int h, int w) {
    for (int r = 0; r < h; ++r) {  // row scan
      int c = 0;
      while (c < w-2) {
        int candy = board[r][c];
        if (candy == 0) { ++c; continue; }
        if (c+2 < w && board[r][c+1] == candy && board[r][c+2] == candy) {
          crushes.insert({r, c});
          crushes.insert({r, c+1});
          crushes.insert({r, c+2});
          group_by_col[c].insert(r);
          group_by_col[c+1].insert(r);
          group_by_col[c+2].insert(r);
          int i = 3;
          while (c + i < w && board[r][c+i] == candy) {
            crushes.insert({r, c+i});
            group_by_col[c+i].insert(r);
            ++i;
          }
          c += i;
        } else {
          ++c;
        }
      }
    }

    for (int c = 0; c < w; ++c) { // column scan
      int r = 0;
      while (r < h-2) {
        int candy = board[r][c];
        if (candy == 0) { ++r; continue; }
        if (r+2 < h && board[r+1][c] == candy && board[r+2][c] == candy) {
          crushes.insert({r, c});
          crushes.insert({r+1, c});
          crushes.insert({r+2, c});
          group_by_col[c].insert(r);
          group_by_col[c].insert(r+1);
          group_by_col[c].insert(r+2);

          int i = 3;
          while (r + i < h && board[r+i][c] == candy) {
            crushes.insert({r+i, c});
            group_by_col[c].insert(r+i);
            ++i;
          }
          r += i;
        } else {
          ++r;
        }
      }
    }
  }

  void dropCandies(vector<vector<int>>& board, set<pair<int, int>>& crushes,
                   unordered_map<int, set<int>>& group_by_col, int h, int w) {
    for (auto& kv : group_by_col) {
      int col = kv.first;
      for (int r_crushed : kv.second) { // for each crushed candy, drop all the cells above it down by one
        for (int r = r_crushed - 1; r >= 0; --r) {
          board[r+1][col] = board[r][col];
        }
        board[0][col] = 0; // empty dropped cell
      }
    }
  }

public:
  void printBoard(vector<vector<int>>& board, int h, int w) {
    cout << "Current Board:\n";
    for (int r = 0; r < h; ++r) {
      for (int c = 0; c < w; ++c) {
        cout << setw(4) << std::left << board[r][c] << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }

  vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    int h = board.size(); // height: # of rows
    int w = board[0].size(); // width: # of columns

    set<pair<int, int>> crushes; // set of <row index, col index> to crush
    unordered_map<int, set<int>> group_by_col; // col index : set of row indexes to be crashed
    // printBoard(board, h, w);
    checkBoard(board, crushes, group_by_col, h, w);

    if (crushes.empty()) return board;
    else {
      // crushing candies
      for (auto& k : crushes) {
        board[k.first][k.second] = 0;
      }
      // printBoard(board, h, w);

      // dropping candies
      dropCandies(board, crushes, group_by_col, h, w);
      // printBoard(board, h, w);

      // continue to crush until we'are done
      candyCrush(board);
      return board;
    }
  }
};


int main()
{
  Solution sol;
  vector<vector<int>> board {{110,5,112,113,114}, {210,211,5,213,214}, {310,311,3,313,314}, {410,411,412,5,414}, {5,1,512,3,3}, {610,4,1,613,614}, {710,1,2,713,714}, {810,1,2,1,1}, {1,1,2,2,2}, {4,1,4,4,1014}};
  sol.candyCrush(board);
  sol.printBoard(board, board.size(), board[0].size());
}
