#include "common.hpp"


class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k < 0 || t < 0) return false;

    set<long> num_set;

    for (int i = 0; i < nums.size(); ++i) {
      if (num_set.size() > k) num_set.erase(nums[i - k - 1]);

      auto it_lo = num_set.lower_bound((long)(nums[i]) - t);
      // auto it_up = num_set.upper_bound(nums[i] + t);

      // cout << (long)nums[i] - t << endl;
      // if (it_lo == num_set.end()) cout << "end\n";
      if (it_lo != num_set.end() && abs(*it_lo - (long)nums[i]) <= t) return true;
      // if (std::distance(it_lo, it_up) >= 1) return true;

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
