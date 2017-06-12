#include "common.hpp"

// time:
// space:
class Solution {
public:
  int distributeCandies(vector<int>& candies) {

    sort(candies.begin(), candies.end());

    int cur_kind = candies[0];
    int num_kinds = 1;
    for (const int candy : candies) {
      if (candy != cur_kind) {
        num_kinds += 1;
        cur_kind = candy;
      }
    }

    return num_kinds > candies.size() / 2 ? candies.size()/2 : num_kinds;
  }
};

int main()
{
  Solution sol;
  vector<int> candies1 {1,1,2,2,3,3};
  cout << sol.distributeCandies(candies1) << endl;
  vector<int> candies2 {1,1,1,1,3,3};
  cout << sol.distributeCandies(candies2) << endl;
}
