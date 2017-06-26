#include "common.hpp"

// time: O(1)
// space: O(1)

// the idea is to repeatedly flip the least-significant 1-bit to 0 until
// the number becomes zero. the least-significant 1-bit in n always corresponds
// to 0-bit in (n-1), therefore anding n and n-1 always flip the least-sigficant
// 1-bit in n to 0 while preserving all other bits.
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int counter = 0;
    while (n) {
      ++counter;
      n &= n - 1;
    }
    return counter;
  }
};

int main()
{
  Solution sol;
  cout << sol.hammingWeight(11) << endl;
  cout << sol.hammingWeight(0xFF) << endl;
  cout << sol.hammingWeight(0x80) << endl;
}
