#include "common.hpp"

// sort
//
// Sort the array, the max product of three numbers can come from two sources:
// the maximum element, 2nd maximum element and 3rd maximum element, or the
// maximum element, minimum element and 2nd minimum element (in case the two
// smallest elements are negative, their product will be positive).

class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return max(nums[n-1] * nums[n-2] * nums[n-3], nums[n-1] * nums[0] * nums[1]);
  }
};

// linear scan

class Solution2 {
public:
  int maximumProduct(vector<int>& nums) {
    int max1 = numeric_limits<int>::min();
    int max2 = max1, max3 = max1;

    int min1 = numeric_limits<int>::max();
    int min2 = min1;

    for (int num : nums) {
      if (num >= max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (num >= max2) {
        max3 = max2;
        max2 = num;
      } else if (num > max3) {
        max3 = num;
      }

      if (num <= min1) {
        min2 = min1;
        min1 = num;
      } else if (num < min2) {
        min2 = num;
      }
    }

    return max(max1 * max2 * max3, max1 * min1 * min2);
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums {1, 2, 3};
  cout << sol.maximumProduct(nums) << endl;
}
