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


// one-pass: map + set
// use a set to store visited nums to eliminate duplications.

class Solution2 {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0; // k cannot be negative

    int len = nums.size();
    unordered_set<int> nums_set; // store unique numbers
    unordered_map<int, int> nums_map;

    int pair_counter = 0;
    for (int i = 0; i < len; ++i) {
      nums_map[nums[i]] += 1;

      if (nums_set.count(nums[i]) == 0 && k > 0) {
        nums_set.emplace(nums[i]);
        if (nums_map.find(nums[i] - k) != nums_map.end()) {
          ++pair_counter;
        }

        if (nums_map.find(nums[i] + k) != nums_map.end()) {
          ++pair_counter;
        }
      } else if (nums_set.count(nums[i]) == 0 && k == 0) {
        if (nums_map[nums[i]] > 1) {
          nums_set.emplace(nums[i]);
          ++pair_counter;
        }
      }
    }
    return pair_counter;
  }
};


// credit: https://discuss.leetcode.com/topic/81676/c-java-clean-code-with-explanation-set-map

// one-pass: set + map
// use a set to store smaller numbers that contribute to pairs
// for each num in the array,
//   - if num - k is in the map, insert num - k into the set;
//   - if num + k is in the map, insert num into the set
// return the size of the set

// note: it handles k == 0 case directly, no need for a special case!

class Solution3 {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0; // k cannot be negative

    int len = nums.size();
    unordered_set<int> results;
    unordered_map<int, int> nums_map;

    for (int i = 0; i < len; ++i) {
      if (nums_map.find(nums[i] - k) != nums_map.end()) {
        results.emplace(nums[i] - k);
      }

      if (nums_map.find(nums[i] + k) != nums_map.end()) {
        results.emplace(nums[i]);
      }

      nums_map[nums[i]] += 1;
    }

    return results.size();
  }
};

int main()
{
  Solution3 sol;
  // vector<int> nums {3, 1, 4, 1, 5};
  // vector<int> nums {1, 2, 3, 4, 5};
  // vector<int> nums {1, 3, 1, 5, 4};
  vector<int> nums {-1,-2,-3};
  cout << sol.findPairs(nums, 1) << endl;
}
