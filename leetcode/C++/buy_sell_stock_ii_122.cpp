#include "common.hpp"

// find each pair of (valley, peak), sum their differences.

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int cur_valley {numeric_limits<int>::max()};
    int cur_max = 0;
    int max_profit = 0;
    int len = prices.size();

    for (int i = 0; i < len; ++i) {
      if (prices[i] <= cur_valley) {
        if (cur_max) {
          max_profit += cur_max;
          cur_max = 0;
        }
        cur_valley = prices[i];
      } else {
        if (prices[i] - cur_valley > cur_max) cur_max = prices[i] - cur_valley;
        else { // a new valley found
          max_profit += cur_max;
          cur_valley = prices[i];
          cur_max = 0;
        }
      }
      // cout << "cur valley: " << cur_valley << endl;
    }

    if (cur_max) max_profit += cur_max;

    return max_profit;
  }
};

int main()
{
  Solution sol;
  vector<int> prices {7, 1, 5, 3, 6, 4};
  cout << sol.maxProfit(prices) << endl;

  vector<int> prices2 {2,1,2,0,1};
  cout << sol.maxProfit(prices2) << endl;
}
