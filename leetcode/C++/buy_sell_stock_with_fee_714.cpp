#include "common.hpp"

// time: O(n^2), TLE...

class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if (!n) return 0;

    int k = n/2;
    auto buysells_ptr = new vector<pair<int, int>> (k+1, {0,0});
    auto& buysells = *buysells_ptr;

    for (int i = 1; i <= k; ++i) {
      buysells[i].first = numeric_limits<int>::min();
    }

    for (int p : prices) {
      for (int i = 1; i <= k; ++i) {
        buysells[i].first = max(buysells[i].first, buysells[i-1].second - p);
        buysells[i].second = max(buysells[i].second, buysells[i].first + p - fee);
      }
    }

    return buysells[k].second;
  }
};


// DP: at the end of each day, we either hold one stock or release one stock previously held,
// we calculate max profit we can make under each of two cases for each day, so at the end
// of last day, we'll have max profit.

class Solution2 {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int hold = numeric_limits<int>::min(), release = 0;

    for (int p : prices) {
      hold = max(hold, release - p); // max profit if hold one stock the current point
      release = max(release, p + hold - fee); // max profit if release the held stock at the current point
    }

    return release;
  }
};

int main()
{
  Solution2 sol;
  // vector<int> prices {1, 3, 2, 8, 4, 9};
  vector<int> prices {1, 4, 3, 6, 3, 9};
  cout << sol.maxProfit(prices, 2) << endl;
}
