#include "common.hpp"

// Hash Table + Linear Scan

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> elem2pos_list;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (elem2pos_list.count(num)) {
        auto& pos_list = elem2pos_list[num];
        for (int j = 0; j < pos_list.size(); ++j) {
          if (i - pos_list[j] <= k) return true;
        }
      }
      elem2pos_list[num].push_back(i);
    }

    return false;
  }
};


// Hash Table + Binary Search

class Solution2 {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> elem2pos_list;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (elem2pos_list.count(num)) {
        auto& pos_list = elem2pos_list[num];
        // 0,3, k = 2, i = 6, needs to find out if there is elements >= 4
        auto it = std::lower_bound(pos_list.begin(), pos_list.end(), i - k);
        if (it != pos_list.end()) return true;
      }
      elem2pos_list[num].push_back(i);
    }

    return false;
  }
};


// Hash Table + Sliding Window

class Solution3 {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> num_set;

    for (int i = 0; i < nums.size(); ++i) {
      if (num_set.size() > k) num_set.erase(nums[i - k - 1]);
      if (num_set.count(nums[i])) return true;
      num_set.insert(nums[i]);
    }

    return false;
  }
};


int main()
{
  vector<int> nums {1, 0, 1, 1}; // true
  Solution3 sol;
  cout << std::boolalpha << sol.containsNearbyDuplicate(nums, 1) << endl;
}
