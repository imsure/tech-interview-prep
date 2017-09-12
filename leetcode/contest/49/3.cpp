#include "../common.hpp"

class Solution {
public:
  int findMin(vector<vector<int>>& forest, int h, int w, pair<int, int>& xy, int prev_min) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (forest[i][j] != 0 && forest[i][j] != 1 && forest[i][j] > prev_min) {
          xy.first = i;
          xy.second = j;
          return forest[i][j];
        }
      }
    }
  }

  bool findWay(vector<vector<int>>& forest, pair<int, int> cur_xy, pair<int, int> min_xy, int& step) {
    while (true) {
      if (cur_xy.first == 0 && cur_xy.second == 0) return false;
      if (cur_xy.first == min_xy.first && cur_xy.second == min_xy.second) {
        return true;
        forest[min_xy.first][min_xy.second] = 1;
      }
      if (cur_xy.first != 1 && cur_xy.second == 0) return false;
    }
  }

  int cutOffTree(vector<vector<int>>& forest) {
    int h = forest.size();
    int w = forest[0].size();

    int prev_min = -1;
    pair<int, int> min_xy;
    int cur_min = findMin(forest, h, w, min_xy, prev_min);
    prev_min = cur_min;

    pair<int, int> cur_xy = make_pair(0, 0);
    int step = 0;
    findWay(cur_xy, min_xy, step);
  }
};


int main()
{
  vector<int> nums {1,3,5,4,7};
  Solution sol;
  cout << sol.findLengthOfLCIS(nums) << endl;
}
