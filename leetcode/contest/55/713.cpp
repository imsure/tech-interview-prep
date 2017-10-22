#include "../common.hpp"

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < k) {
        ++count;
        int prod = nums[i];
        for (int j = i + 1; j < nums.size(); ++j) {
          prod *= nums[j];
          if (prod < k) ++count;
          else break;
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {10, 5, 2, 6};
  cout << sol.numSubarrayProductLessThanK(nums, 100) << endl;
}
