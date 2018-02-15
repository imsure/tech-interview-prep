#include "common.hpp"


// Erase

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == val) {
        nums.erase(nums.begin() + i);
        --i;
      }
    }

    return nums.size();
  }
};


// Two pointers + Swap

class Solution2 {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;
    int count = 0;
    int front = 0, end = nums.size() - 1;

    while (front <= end) {
      // end should always point to element that is not 'val'
      while (end > front && nums[end] == val) {
        --end;
        ++count;
      }
      if (nums[front] == val) {
        swap(nums[front], nums[end]);
        --end;
        ++count;
      }
      ++front;
    }

    return nums.size() - count;
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums {3,3,2,2};
  // vector<int> nums {3,2,2,3};
  // vector<int> nums {2,2,3,3};
  cout << sol.removeElement(nums, 3) << endl;
  for (int num : nums) cout << num << ',';
  cout << '\n';
}
