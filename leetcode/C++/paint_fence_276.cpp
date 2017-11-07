#include "common.hpp"

// At post i (i > 2), there are 2 cases to consider:
// - the previous two posts (i-1 and i-2) are of different colors;
// - the previous two posts (i-1 and i-2) are of same color;
// so the total ways of painting at post i is the sum of the ways considering both two cases.

// - the previous two posts (i-1 and i-2) are of different colors;
//   # of ways that i-1 and i-2 are different * k
// - the previous two posts (i-1 and i-2) are of same color;
//   # of ways that i-1 and i-2 are same * (k-1)

// time: O(n)
// space: O(1)

class Solution {
public:
  int numWays(int n, int k) {
    if (!n || !k) return 0;
    if (n == 1) return k;
    if (n == 2) return k * k;

    int same = k; // there are total k ways to paint post 1 and 2 with the same color
    int diff = k * (k-1); // there are total k(k-1) ways to paint post 1 and 2 with the different color

    for (int i = 3; i <= n; ++i) {
      int tmp = same;
      same = diff;
      diff = tmp * (k-1) + diff * (k-1);
    }

    return same + diff;
  }
};


int main()
{
  Solution sol;
  cout << sol.numWays(3, 3) << endl;
  cout << sol.numWays(4, 3) << endl;
}
