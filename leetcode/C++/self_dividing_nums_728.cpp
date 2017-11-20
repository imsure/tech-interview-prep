#include "common.hpp"

class Solution {
private:
  bool checkNum(int n) {
    int m = n;
    while (n > 0) {
      int d = n - (n / 10) * 10; // extract right-most digit
      if (d == 0) return false;
      if (m % d) return false;
      n = n / 10;
    }
    return true;
  }

public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;
    for (int n = left; n <= right; ++n) {
      if (checkNum(n)) ans.push_back(n);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> res = sol.selfDividingNumbers(1, 22);
  for (int n : res) cout << n << endl;
}
