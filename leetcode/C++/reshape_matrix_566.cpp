#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int h = nums.size(); // height
    int w = nums[0].size(); // width

    if (h * w != r * c) {
      return nums; // matrix cannot be reshaped
    }

    vector<int> new_row (c, 0);
    vector<vector<int>> new_matrix (r, new_row);

    int cur_row = 0, cur_col = 0;
    for (const auto& row : nums) {
      for (const int num : row) {
        new_matrix[cur_row][cur_col++] = num;
        if (cur_col == c) { // the current row has been fiiled up, advance
          cur_row += 1;
          cur_col = 0;
        }
      }
    }

    return new_matrix;
  }
};

int main()
{
}
