#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// time: O(mn), m rows, n columns
// space: O(1)
class Solution {
public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    if (picture.size() == 0) return 0;

    int lp_count = 0;
    for (int row = 0; row < picture.size(); ++row) {
      int bcount_row = 0; // count # of black pixel in a row
      int col_index;
      for (int col = 0; col < picture[row].size(); ++col) {
        if (picture[row][col] == 'B') {
          bcount_row++;
          col_index = col;
        }
      }
      if (bcount_row == 1) {
        int bcount_col = 0;
        for (int row2 = 0; row2 < picture.size(); ++row2) {
          if (picture[row2][col_index] == 'B') {
            bcount_col++;
          }
        }
        if (bcount_col == 1) {
          lp_count++;
        }
      }
    }

    return lp_count;
  }
};

int main()
{
  vector<char> r1 {'W', 'W', 'B'};
  vector<char> r2 {'W', 'B', 'W'};
  vector<char> r3 {'B', 'W', 'W'};
  vector<vector<char>> picture1 {r1, r2, r3};

  vector<char> r4 {'B', 'W', 'B'};
  vector<char> r5 {'W', 'B', 'W'};
  vector<char> r6 {'B', 'W', 'W'};
  vector<vector<char>> picture2 {r4, r5, r6};

  Solution sol;
  cout << sol.findLonelyPixel(picture1) << endl;
  cout << sol.findLonelyPixel(picture2) << endl;
}
