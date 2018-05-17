#include "../common.hpp"


class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> ans;
    int n = S.size();

    int i = 0, j = 0;
    while (i < n) {
      char cur = S[i];
      j = i + 1;
      while (j < n && S[j] == cur) ++j;
      if (j - i >= 3) {
        ans.push_back(vector<int> {i, j - 1});
      }
      i = j;
    }

    return ans;
  }
};


int main()
{
  vector<vector<int>> res;
  Solution sol;
  res = sol.largeGroupPositions("abbxxxxzzy");
  for (auto r : res) cout << r[0] << ',' << r[1] << endl;
}
