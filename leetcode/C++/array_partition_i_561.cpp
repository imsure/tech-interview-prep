#include "common.hpp"

// time:
// space:
class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }

    return sum;
  }
};

int main()
{
  vector<int> nums {1,4,3,2};
  Solution sol;
  cout << sol.arrayPairSum(nums) << endl;

  vector<int> nums2 {1,4,3,2,5,6};
  cout << sol.arrayPairSum(nums2) << endl;
}
