#include "common.hpp"

// time:
// space:
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
