#include "../common.hpp"

class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if (!n) return 0;

    int valley = prices[0];
    int peak = prices[0];
    int max_profit = 0;
    int prev_valley = -1, prev_peak = -1;

    int i = 0;
    while (i < n) {
      while (i < n - 1 && prices[i] >= prices[i+1]) ++i;
      valley = prices[i];
      while (i < n - 1 && prices[i] <= prices[i+1]) ++i;
      peak = prices[i];
      if (peak - valley - fee > 0) {
        //cout << "valley: " << valley << ", peak: " << peak << endl;
        //cout << "prev valley: " << prev_valley << ", prev peak: " << prev_peak << endl;
        if (prev_valley == -1 && prev_peak == -1) max_profit += peak - valley - fee;
        else if (prev_peak == -1 && prev_valley >= 0) max_profit += peak - min(valley, prev_valley) - fee;
        else {
          if (peak - valley - fee + prev_peak - prev_valley - fee >= peak - prev_valley - fee) {
            max_profit += peak - valley - fee;
          } else {
            max_profit += peak - prev_valley - fee;
            max_profit -= prev_peak - prev_valley - fee;
          }
        }
        prev_peak = peak;
      }
      prev_valley = valley;
      //cout << "max_profit: " << max_profit << endl;
      ++i;
    }

    return max_profit;
  }
};

int main()
{
  vector<int> prices {1, 3, 2, 8, 4, 9};
  Solution sol;
  cout << sol.maxProfit(prices, 2) << endl;
}
