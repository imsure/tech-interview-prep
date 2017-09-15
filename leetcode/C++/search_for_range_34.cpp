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

int main()
{
  Solution sol;
  vector<int> nums {5,7,7,8,8,8};
  vector<int> range = sol.searchRange(nums, 8);
  cout << range[0] << ", " << range[1] << endl;
}
