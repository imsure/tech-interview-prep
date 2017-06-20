#include "common.hpp"

// time:
// space:
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> elem_count;
    for (const int num : nums) {
      if (elem_count.find(num) == elem_count.end()) {
        elem_count[num] = 1;
      } else {
        elem_count[num] += 1;
      }
    }

    int majority_thresh = nums.size() >> 1;
    int major_elem, major_elem_count = 0;
    for (const auto& keyval : elem_count) {
      if (keyval.second >= majority_thresh) {
        if (keyval.second > major_elem_count) {
          major_elem_count = keyval.second;
          major_elem = keyval.first;
        }
      }
    }

    return major_elem;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {1,5,5,3,1};
  cout << sol.majorityElement(nums) << endl;
  vector<int> nums2 {3,2,3};
  cout << sol.majorityElement(nums2) << endl;
}
