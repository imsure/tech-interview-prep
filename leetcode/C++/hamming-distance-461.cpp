#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// time: O(1)
// space: O(1)
class Solution {
public:
  int hammingDistance(int x, int y) {
    int dist = 0;
    for (int i = 0; i < 32; ++i) {
      int mask = 0x1 << i;
      if ((x & mask) != (y & mask)) {
        dist++;
      }
    }
    return dist;
  }
};

// a more clever solution
class Solution2 {
public:
  int hammingDistance(int x, int y) {
    int dist = 0;
    int z = x ^ y;
    while (z) {
      ++dist;
      z &= z - 1;
    }

    return dist;
  }
};

int main()
{
  Solution sol;
  cout << sol.hammingDistance(1, 4) << endl;

  Solution2 sol2;
  cout << sol2.hammingDistance(10, 5) << endl;
}
