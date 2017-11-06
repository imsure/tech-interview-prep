#include "common.hpp"

class Solution {
private:
  int maxProfitGreedy(vector<int>& prices) {
    int max_profit = 0;
    for (int i = 0; i < prices.size()-1; ++i) {
      if (prices[i+1] > prices[i])
        max_profit += prices[i+1] - prices[i];
    }

    return max_profit;
  }

public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (!n) return 0;
    if (k > n/2) return maxProfitGreedy(prices);

    auto buysells_ptr = new vector<pair<int, int>> (k+1, {0,0});
    auto& buysells = *buysells_ptr;

    for (int i = 1; i <= k; ++i) {
      buysells[i].first = numeric_limits<int>::min();
    }

    for (int p : prices) {
      for (int i = 1; i <= k; ++i) {
        buysells[i].first = max(buysells[i].first, buysells[i-1].second - p);
        buysells[i].second = max(buysells[i].second, buysells[i].first + p);
      }
    }

    return buysells[k].second;
  }
};

int main()
{
  Solution sol;
  vector<int> prices {7, 1, 5, 3, 6, 4, 8};
  cout << sol.maxProfit(3, prices) << endl;
}
