#include "common.hpp"


class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows <= 0) return ans;

    ans.push_back({1});
    for (int len = 2; len <= numRows; ++len) {
      vector<int> row;
      row.push_back(1);
      for (int i = 1; i < len-1; ++i) {
        auto& prev_row = ans.back();
        row.push_back(prev_row[i-1] + prev_row[i]);
      }
      row.push_back(1);
      ans.push_back(row);
    }

    return ans;
  }
};


int main()
{
  Solution sol;
}
