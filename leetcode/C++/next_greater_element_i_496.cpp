#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    stack<int> nums_stack;
    for (const int num : nums) {
      nums_stack.push(num);
    }

    unordered_map<int, int> nums_map;
    int cur_num, prev_num = -1;
    while (!nums_stack.empty()) {
      cur_num = nums_stack.top();
      if (cur_num < prev_num || prev_num == -1) {
        nums_map[cur_num] = prev_num;
      } else {
        int target;
        do {
          target = nums_map[prev_num];
          prev_num = target;
        } while (target < cur_num && target != -1);
        nums_map[cur_num] = target;
      }
      prev_num = cur_num;
      nums_stack.pop();
    }

    vector<int> res;
    for (const int num : findNums) {
      res.push_back(nums_map[num]);
    }

    return res;
  }
};

int main()
{
  vector<int> nums1 {4,1,2};
  vector<int> nums2 {1,3,4,2};
  Solution sol;
  vector<int> res = sol.nextGreaterElement(nums1, nums2);
  for (const int num : res) {
    cout << num << endl;
  }
}
