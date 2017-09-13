#include "common.hpp"

class Solution {
public:
  bool judgeSquareSum(int c) {
    int d = std::floor(std::sqrt(c));
    int i = 0, j = d;

    while (i <= j) {
      int sum = i * i + j * j;
      if (sum == c) return true;
      if (sum < c) ++i;
      else --j;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  cout << sol.judgeSquareSum(5) << endl;
}
