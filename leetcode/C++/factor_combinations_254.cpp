#include "common.hpp"

// Enforce factors in each combination appear in ascending order to avoid
// duplicated combinations.
// e.g., n = 18, first iteration we find [2,9], then recursively find [2,3,3];
// second iteration we find [3,6], then recursively find [2,3] for 6, but since 3 > 2,
// we know the combination of [3,2,3] has already been found during the previous iterations, we
// just adandon [3,2,3].

class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;

    int factor = 2;
    while (factor <= (int)sqrt(n)) {
      if (n % factor == 0) {
        ans.push_back(vector<int>{factor, n / factor});
        vector<vector<int>> res = getFactors(n / factor);
        for (auto r : res) {
          if (factor > r[0]) continue;
          r.insert(r.begin(), factor);
          ans.push_back(r);
        }
      }
      ++factor;
    }

    return ans;
  }
};


class Solution2 {
private:
  void _getFactors(int start, int n, vector<vector<int>>& ans, vector<int>& path) {
    for (int i = start; i <= sqrt(n); ++i) {
      if (n % i) continue;

      path.push_back(i);
      path.push_back(n/i);
      ans.push_back(path);
      path.pop_back();
      _getFactors(i, n/i, ans, path);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> path;
    _getFactors(2, n, ans, path);
    return ans;
  }
};


int main()
{
  Solution2 sol;
  // vector<vector<int>> ans = sol.getFactors(32);
  vector<vector<int>> ans = sol.getFactors(24);
  // vector<vector<int>> ans = sol.getFactors(18);
  for (auto l : ans) {
    for (int n : l) cout << n << ' ';
    cout << endl;
  }
}
