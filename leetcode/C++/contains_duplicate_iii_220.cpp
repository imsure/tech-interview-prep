#include "common.hpp"

// set + sliding windows
//
// Linear scan the array, use a set to keep track of a sorted windows of k elements,
// when a new element x comes, find the first element in the set that is >= (x-t),
// if this element y does not exist, then move on, otherwise calculate the absolute
// difference between x and y, if difference <= t, return true, otherwise move on.

// time: O(NlogN)
// space: O(k)

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k < 0 || t < 0) return false;

    set<long> num_set;

    for (int i = 0; i < nums.size(); ++i) {
      if (num_set.size() > k) num_set.erase(nums[i - k - 1]);

      // find the first element in the set that is >= (nums[i] - t)
      auto it_lo = num_set.lower_bound((long)(nums[i]) - t);

      if (it_lo != num_set.end() && abs(*it_lo - (long)nums[i]) <= t) return true;

      num_set.insert(nums[i]);
    }

    return false;
  }
};


int main()
{
  vector<int> nums {0, 2147483647};
  // vector<int> nums {-2147483648,-2147483647};
  Solution sol;
  cout << std::boolalpha << sol.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;
  // cout << std::boolalpha << sol.containsNearbyAlmostDuplicate(nums, 3, 3) << endl;
}
