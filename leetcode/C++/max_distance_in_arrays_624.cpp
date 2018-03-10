#include "common.hpp"


class Solution {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    int m = arrays.size();
    int min_val = 10001, min_index;
    int max_val = -10001, max_index;

    for (int i = 0; i < m; ++i) {
      auto& array = arrays[i];
      int sz = array.size();
      if (array[0] < min_val) {
        min_val = array[0];
        min_index = i;
      }
      if (array[sz-1] > max_val) {
        max_val = array[sz-1];
        max_index = i;
      }
    }

    if (min_index != max_index) return max_val - min_val;
    int res1, res2;
    res1 = res2 = numeric_limits<int>::min();
    for (int i = 0; i < m; ++i) {
      auto& array = arrays[i];
      int sz = array.size();
      if (i != min_index) res1 = max(res1, array[sz-1] - min_val);
      if (i != max_index) res2 = max(res2, max_val - array[0]);
    }

    return max(res1, res2);
  }
};



// one-pass

class Solution2 {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    int m = arrays.size();
    int res = numeric_limits<int>::min();
    int min_val = arrays[0][0];
    int max_val = arrays[0][arrays[0].size()-1];

    for (int i = 1; i < m; ++i) {
      auto& arr = arrays[i];
      int sz = arr.size();
      res = max(res, abs(arr[sz-1] - min_val));
      res = max(res, abs(max_val - arr[0]));
      min_val = min(min_val, arr[0]);
      max_val = max(max_val, arr[sz-1]);
    }

    return res;
  }
};


int main()
{
  Solution sol;
}
