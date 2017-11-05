#include "common.hpp"

// wrong approach! failed at test case: 1,2,4,2,5,7,2,4,9,0
// expected: buy at 1, sell at 7, buy at 2, sell at 9, profit: 13
// output: buy at 2, sell at 7, buy at 2, see at 9, profit: 12

// note: greedy approach can only find local optimal, but not global optimal.

// find all pair of (valley, peak) and store their differences
// in an array, then sort the array to pick two largest diffs.

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (!n) return 0;
    int max_profit = 0;
    int peak, valley;
    vector<int> diffs;

    int i = 0;
    while (i < n-1) {
      while (i < n-1 && prices[i] >= prices[i+1]) ++i;
      valley = prices[i];
      while (i < n-1 && prices[i] <= prices[i+1]) ++i;
      peak = prices[i];
      diffs.push_back(peak - valley);
    }

    std::sort(diffs.begin(), diffs.end());
    n = diffs.size();
    if (n > 1) {
      max_profit += diffs[n-1] + diffs[n-2];
    } else if (n == 1) {
      max_profit += diffs[0];
    }

    return max_profit;
  }
};


// divide and conquer: for each possible partition of the array: prices[0...j] and
// prices[j+1...n], calculate the max profit for each of them using the same method
// as in buy and sell stock 1.

// time: o(n^2), got an TLE...

class Solution2 {
private:
  int maxProfit_i(vector<int>& prices, int start, int end) {
    int max_profit = 0, min_price = numeric_limits<int>::max();
    for (int i = start; i <= end; ++i) {
      if (prices[i] < min_price) min_price = prices[i];
      else max_profit = max(max_profit, prices[i] - min_price);
    }

    return max_profit;
  }

public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int max_profit = 0;
    for (int i = 0; i < n; ++i) {
      int max1 = maxProfit_i(prices, 0, i);
      int max2 = maxProfit_i(prices, i+1, n-1);
      max_profit = max(max_profit, max1 + max2);
    }

    return max_profit;
  }
};


class Solution3 {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy1, buy2, sell1, sell2;

    buy1 = buy2 = numeric_limits<int>::min();
    sell1 = sell2 = 0;

    for (auto p : prices) {
      buy1 = max(buy1, -p); // we want buy1 as low as possible
      sell1 = max(sell1, p + buy1);
      buy2 = max(buy2, sell1 - p);
      sell2 = max(sell2, p + buy2);
    }

    return sell2;
  }
};


int main()
{
  Solution3 sol;
  vector<int> prices {1,2,4,2,5,7,2,4,9,0};
  cout << sol.maxProfit(prices) << endl;
}
