#include "common.hpp"


class Solution {
private:
  int calculate(int n, int i) {
    if (i == 0) return 1;
    uint64_t m = 1;
    for (int j = 0; j < i; ++j) {
      m *= (n - j);
      m /= (j + 1);
    }
    return m;
  }

public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans;
    if (rowIndex < 0) return ans;

    int sz = rowIndex + 1;
    int half_sz = sz / 2;
    stack<int> buf;
    for (int i = 0; i < half_sz; ++i) {
      int res = calculate(rowIndex, i);
      buf.push(res);
      ans.push_back(res);
    }
    if (sz % 2) ans.push_back(calculate(rowIndex, half_sz));
    while (!buf.empty()) {
      ans.push_back(buf.top());
      buf.pop();
    }

    return ans;
  }
};


class Solution2 {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans (rowIndex + 1, 0);
    ans[0] = 1;  // first row
    for (int row = 1; row <= rowIndex; ++row) {
      for (int i = row; i >= 1; --i) {
        ans[i] += ans[i - 1];
      }
    }

    return ans;
  }
};


int main()
{
  Solution2 sol;
  auto ret = sol.getRow(6);
  for (int n : ret) cout << n << ' ';
  cout << '\n';
}
