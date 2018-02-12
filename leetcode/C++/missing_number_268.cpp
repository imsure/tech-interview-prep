#include "common.hpp"


class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = 0, sum = 0;

    for (int i = 0; i <= n; ++i) {
      total += i;
    }

    for (int num : nums) sum += num;

    return total - sum;
  }
};


int main()
{
  Solution sol;
  vector<int> nums {9,6,4,2,3,5,7,0,1};
  cout << sol.missingNumber(nums) << endl;
}
