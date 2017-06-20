#include "common.hpp"

// time:
// space:
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int min_price {numeric_limits<int>::max()};
    int max_profit = 0;
    int i, len = prices.size();

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
