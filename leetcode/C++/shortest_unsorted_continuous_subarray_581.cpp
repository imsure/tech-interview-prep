#include "common.hpp"


// Make a copy of the array and sort it. Then compare elements
// of the two arrays from both ends. Record the position of the
// first elements that are different on both end and return the
// distance between these two positions.

// time: O(NlogN)
// space: O(N)


class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    vector<int> nums_sorted {nums};
    sort(nums_sorted.begin(), nums_sorted.end());

    int len = nums.size();
    int l = 0, r = len - 1;
    while (l < r) {
      if (nums[l] != nums_sorted[l] && nums[r] != nums_sorted[r]) return r - l + 1;

      if (nums[l] == nums_sorted[l]) ++l;
      if (nums[r] == nums_sorted[r]) --r;
    }

    return 0;
  }
};


int main()
{
  Solution sol;
  // vector<int> nums {2, 6, 4, 8, 10, 9, 15};
  vector<int> nums {2, 4, 8, 10, 15};
  cout << sol.findUnsortedSubarray(nums) << endl;
}
