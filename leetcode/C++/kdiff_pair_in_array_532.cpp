#include "common.hpp"

// build a hashmap {num : times num appeared in the array},
// then iterate through each num in the map, look up if (num - k) in
// the map or not, if yes, a pair was found, otherwise not.

// k = 0 is a special case, because any number's absolution diff to
// itself is 0, so only those numbers whose hashmap[num] >= 2 counts
// as a pair.

// time: O(n)
// space: O(n)

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> unique_nums;

    if (k < 0) return 0;

    int len = nums.size();
    for (int i = 0; i < len; ++i) {
      if (unique_nums.find(nums[i]) == unique_nums.end())
        unique_nums[nums[i]] = 1;
      else
        unique_nums[nums[i]] += 1;
    }

    int pair_counter = 0;
    if (k == 0) {
      for (const auto& keyval : unique_nums) {
        if (keyval.second > 1) {
          ++pair_counter;
        }
      }
      return pair_counter;
    }

    for (const auto& keyval : unique_nums) {
      if (unique_nums.find(keyval.first - k) != unique_nums.end()) {
        ++pair_counter;
      }
    }

    return pair_counter;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {3, 1, 4, 1, 5};
  // vector<int> nums {1, 2, 3, 4, 5};
  // vector<int> nums {1, 3, 1, 5, 4};
  // vector<int> nums {-1,-2,-3};
  cout << sol.findPairs(nums, 1) << endl;
}
