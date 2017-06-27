#include "common.hpp"

// idea: initialize a mask as 0xFFFFFFFF, then repeatedly
// anding mask with num, if the result > 0, left shift mask by 1 bit
// with trailing 0's until the result is 0, then the trailing 0's in
// the mask can be used to identify the valid bits in the input number.

// time: O(1)
// space: O(1)
class Solution {
public:
  int findComplement(int num) {
    unsigned int mask = ~0;
    // find out the mask
    while (mask & num) {
      mask <<= 1;
    }

    return (~mask) & (~num);
  }
};

int main()
{
  Solution sol;
  cout << sol.findComplement(5) << endl;
  cout << sol.findComplement(7) << endl;
  cout << sol.findComplement(-1) << endl;
}
