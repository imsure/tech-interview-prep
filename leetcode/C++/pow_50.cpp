#include "common.hpp"

class Solution {
private:
  double _myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    double y = _myPow(x, n/2);
    return n % 2 ? y * y * x : y * y;
  }

public:
  double myPow(double x, int n) {
    double res = _myPow(x, abs(n));
    return n < 0 ? 1/res : res;
  }
};

int main()
{
  Solution sol;
  cout << sol.myPow(2, 100) << endl;
}
