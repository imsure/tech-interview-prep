#include "common.hpp"


class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) lo = mid + 1;
      else hi = mid - 1;
    }

    return lo;
  }
};



class Solution2 {
public:
  int searchInsert(vector<int>& nums, int target) {
    // find the position of the first element in nums that is no less than target
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end()) return nums.size();

    int pos = std::distance(nums.begin(), it);
    if (*it == target) return pos;
    else return pos;
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums {1, 3, 5, 6};
  cout << sol.searchInsert(nums, 5) << endl;  // 2
  cout << sol.searchInsert(nums, 2) << endl;  // 1
  cout << sol.searchInsert(nums, 7) << endl;  // 4
  cout << sol.searchInsert(nums, 0) << endl;  // 0
}
