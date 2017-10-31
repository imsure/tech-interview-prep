#include "../common.hpp"

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int len = bits.size();

    int i = 0;
    while (i + 1 < len) {
      if (bits[i] == 0) ++i;
      if (bits[i] == 1) i += 2;
    }

    if (i >= len) return false;
    return bits[i] == 0;
  }
};

int main()
{
  Solution sol;
  // vector<int> bits {1,0,0};
  // vector<int> bits {1,1,1,0};
  vector<int> bits {0,0,1,0};
  cout << sol.isOneBitCharacter(bits) << endl;
}
