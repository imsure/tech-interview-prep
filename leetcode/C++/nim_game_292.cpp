#include "common.hpp"

// time:
// space:
class Solution {
public:
  bool canWinNim(int n) {
    return n % 4? true : false;
  }
};

int main()
{
  Solution sol;
  cout << sol.canWinNim(1) << endl;
}
