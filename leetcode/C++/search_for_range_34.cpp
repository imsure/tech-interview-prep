#include "common.hpp"

// time: O(logN)
// space: O(1)

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> range {-1, -1};
    if (!len) return range;

    // find the first num that is not less than target
    auto low = std::lower_bound(nums.begin(), nums.end(), target);
    // find the first num that is greater than target
    auto up = std::upper_bound(nums.begin(), nums.end(), target);

    if (low == nums.end()) return range;

    if (*low == target) {
      range[0] = low - nums.begin();
      range[1] = --up - nums.begin();
    }
    return range;
  }
};



// Given a sorted array nums[lo...hi] and a 'target' value, return the index
// of the first num in the vector that is not less than target.
// Return -1 if not found.
int my_lower_bound(vector<int>& nums, int lo, int hi, int target)
{
  if (nums[lo] >= target) return lo;
  if (nums[hi] < target) return -1;

  int mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (nums[mid] < target) lo = mid + 1;
    else hi = mid;
  }

  return lo;
}

class Solution2 {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> range {-1, -1};
    if (!len) return range;

    // find the first num that is not less than target
    int low = my_lower_bound(nums, 0, len-1, target);
    if (low == -1 || nums[low] != target) return range;

    // find the first num that is greater than target
    int hi = my_lower_bound(nums, 0, len-1, target+1);

    range[0] = low;
    range[1] = hi == -1 ? len-1 : --hi;

    return range;
  }
};

int main()
{
  Solution2 sol;
  vector<int> nums {5,7,7,8,8,8,9};
  vector<int> range = sol.searchRange(nums, 8);
  cout << range[0] << ", " << range[1] << endl;
}
