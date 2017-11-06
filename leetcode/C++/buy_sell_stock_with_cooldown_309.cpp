#include "common.hpp"

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int hold = numeric_limits<int>::min();
    int release = 0;
    int cooldown = 0;

    for (int p : prices) {
      hold = max(hold, cooldown - p); // we can only hold a new stock if we cooldown at previous stock
      // if we choose to cooldown at this point, the profit we get is pre_release.
      cooldown = max(cooldown, release);
      release = max(release, p + hold); // max profit we can get if choose to release at current stock
    }

    return max(release, cooldown);
  }
};

int main()
{
  Solution sol;
  vector<int> prices {1,2,3,0,2};
  cout << sol.maxProfit(prices) << endl;
}
