#include "common.hpp"

// my original solution, not with so good code quality, some redundant code,
// some ambiguous namings, e.g., isValid, inBoard is better

// time: O(n) where n is # of total squares
// space: O(1)
class Solution {
private:
  bool isValid(int row, int col, int nRows, int nCols) {
    return row >= 0 && row < nRows && col >= 0 && col < nCols ? true : false;
  }

public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board.empty()) return board;

    int row = click[0], col = click[1];
    int nRows = board.size(), nCols = board[0].size();
    char square = board[row][col];
    if (square == 'M') {
      board[row][col] = 'X';
      return board;
    } else if (square == 'E') {
      int mine_count = 0;

      if (isValid(row, col - 1, nRows, nCols) && board[row][col-1] == 'M') ++mine_count;
      if (isValid(row, col + 1, nRows, nCols) && board[row][col+1] == 'M') ++mine_count;
      if (isValid(row - 1, col, nRows, nCols) && board[row-1][col] == 'M') ++mine_count;
      if (isValid(row + 1, col, nRows, nCols) && board[row+1][col] == 'M') ++mine_count;
      if (isValid(row + 1, col + 1, nRows, nCols) && board[row+1][col+1] == 'M') ++mine_count;
      if (isValid(row + 1, col - 1, nRows, nCols) && board[row+1][col-1] == 'M') ++mine_count;
      if (isValid(row - 1, col - 1, nRows, nCols) && board[row-1][col-1] == 'M') ++mine_count;
      if (isValid(row - 1, col + 1, nRows, nCols) && board[row-1][col+1] == 'M') ++mine_count;

      if (mine_count) {
        board[row][col] = std::to_string(mine_count)[0];
      } else {
        board[row][col] = 'B';
        if (isValid(row, col - 1, nRows, nCols) && board[row][col-1] == 'E') {
          vector<int> nextclick {row, col-1};
          updateBoard(board, nextclick);
        }
        if (isValid(row, col + 1, nRows, nCols) && board[row][col+1] == 'E') {
          vector<int> nextclick {row, col+1};
          updateBoard(board, nextclick);
        }
        if (isValid(row - 1, col, nRows, nCols) && board[row-1][col] == 'E') {
          vector<int> nextclick {row-1, col};
          updateBoard(board,  nextclick);
        }
        if (isValid(row + 1, col, nRows, nCols) && board[row+1][col] == 'E') {
          vector<int> nextclick {row+1, col};
          updateBoard(board, nextclick);
        }
        if (isValid(row + 1, col + 1, nRows, nCols) && board[row+1][col+1] == 'E') {
          vector<int> nextclick {row+1, col+1};
          updateBoard(board, nextclick);
        }
        if (isValid(row + 1, col - 1, nRows, nCols) && board[row+1][col-1] == 'E') {
          vector<int> nextclick {row+1, col-1};
          updateBoard(board, nextclick);
        }
        if (isValid(row - 1, col - 1, nRows, nCols) && board[row-1][col-1] == 'E') {
          vector<int> nextclick {row-1, col-1};
          updateBoard(board, nextclick);
        }
        if (isValid(row - 1, col + 1, nRows, nCols) && board[row-1][col+1] == 'E') {
          vector<int> nextclick {row-1, col+1};
          updateBoard(board, nextclick);
        }
      }
    } else {
      return board;
    }

    return board;
  }
};

// credit: https://discuss.leetcode.com/topic/80873/c-dfs-solution-easy-to-understand
// better coding quality

class Solution2 {
private:
  bool inBoard(int row, int col, int nRows, int nCols) {
    return row >= 0 && row < nRows && col >= 0 && col < nCols ? true : false;
  }

  void reveal(vector<vector<char>>& board, int row, int col) {
    int nRows = board.size(), nCols = board[0].size();
    if (inBoard(row, col, nRows, nCols) == false) return;

    int mine_count = 0;
    if (inBoard(row, col - 1, nRows, nCols) && board[row][col-1] == 'M') ++mine_count;
    if (inBoard(row, col + 1, nRows, nCols) && board[row][col+1] == 'M') ++mine_count;
    if (inBoard(row - 1, col, nRows, nCols) && board[row-1][col] == 'M') ++mine_count;
    if (inBoard(row + 1, col, nRows, nCols) && board[row+1][col] == 'M') ++mine_count;
    if (inBoard(row + 1, col + 1, nRows, nCols) && board[row+1][col+1] == 'M') ++mine_count;
    if (inBoard(row + 1, col - 1, nRows, nCols) && board[row+1][col-1] == 'M') ++mine_count;
    if (inBoard(row - 1, col - 1, nRows, nCols) && board[row-1][col-1] == 'M') ++mine_count;
    if (inBoard(row - 1, col + 1, nRows, nCols) && board[row-1][col+1] == 'M') ++mine_count;

    if (mine_count) {
      board[row][col] = '0' + mine_count; // better than std::to_string(mine_count)[0] !
    } else {
      board[row][col] = 'B';
      reveal(board, row, col - 1);
      reveal(board, row, col + 1);
      reveal(board, row - 1, col);
      reveal(board, row + 1, col);
      reveal(board, row - 1, col - 1);
      reveal(board, row - 1, col + 1);
      reveal(board, row + 1, col + 1);
      reveal(board, row + 1, col - 1);
    }
  }

public:
 vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    }

    reveal(board, click[0], click[1]);
    return board;
  }
};

int main()
{
  vector<vector<char>> board;
  vector<char> row1 {'E', 'E', 'E', 'E', 'E'};
  vector<char> row2 {'E', 'E', 'M', 'E', 'E'};
  vector<char> row3 {'E', 'E', 'E', 'E', 'E'};
  vector<char> row4 {'E', 'E', 'E', 'E', 'E'};
  board.push_back(row1);
  board.push_back(row2);
  board.push_back(row3);
  board.push_back(row4);

  Solution sol;
  vector<int> click {3, 0};
  sol.updateBoard(board, click);

  Solution sol2;
  sol2.updateBoard(board, click);
}
