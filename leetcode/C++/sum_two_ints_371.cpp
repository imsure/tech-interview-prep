#include "common.hpp"

// time:
// space:
class Solution {
public:
  int getSum(int a, int b) {
    int sum = 0;
    int mask = 1;
    bool carry = false;
    for (int i = 0; i < 32; ++i) {
      if ((a & mask) && (b & mask)) {
        if (carry) {
          sum |= 1 << i;
        } else {
          carry = true;
        }
      } else if ((a & mask) || (b & mask)) {
        if (!carry) {
          sum |= 1 << i;
        }
      } else {
        if (carry) {
          sum |= 1 << i;
          carry = false;
        }
      }

      mask = 1 << (i + 1);
    }

    return sum;
  }
};

int main()
{
  Solution sol;
  cout << sol.getSum(1, 2) << endl;
  cout << sol.getSum(4, 5) << endl;
  cout << sol.getSum(204, 55) << endl;
}
