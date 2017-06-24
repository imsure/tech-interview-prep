#include "common.hpp"

// One pass solution, see: https://leetcode.com/articles/best-time-buy-and-sell-stock/
// Is it Greedy or Dynamic Programming?
// time: O(n)
// space: O(1)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int min_price {numeric_limits<int>::max()};
    int max_profit = 0;
    int i, len = prices.size();

    // the idea is to find the largest peak following the smallest valley.
    // variable min_price corresponds to the smallest valley, and max_profit
    // is the maximum difference between between selling price and min_price.
    // for each price in the array, we either update min_price or update max_profit.
    // At the end of the scan, max_profit holds the result.

    // From DP point of view, at position i+1, the max profit is either the max profit
    // at the position i, or is a new value (prices[i+1] - min_price). The idea is similar
    // to max subarray sum problem (https://leetcode.com/problems/maximum-subarray).
    for (i = 0; i < len; ++i) {
      if (prices[i] < min_price) {
        min_price = prices[i];
      } else if (prices[i] - min_price > max_profit) {
        max_profit = prices[i] - min_price;
      }
    }

    return max_profit;
  }
};

int main()
{
  Solution sol;
  vector<int> prices {7, 1, 5, 3, 6, 4};
  cout << sol.maxProfit(prices) << endl;

  vector<int> prices2 {7, 6, 5, 4};
  cout << sol.maxProfit(prices2) << endl;
}
