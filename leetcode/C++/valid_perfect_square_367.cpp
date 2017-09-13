#include "common.hpp"

class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 0, right = num;

    long mid, square;
    while (left <= right) {
      mid = (left + right) / 2;
      square = mid * mid;
      if (square == num) return true;
      if (square < num) left = (int) mid + 1;
      else right = (int) mid - 1;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  cout << sol.isPerfectSquare(2147483647) << endl;
}
