#include "common.hpp"

// time:
// space:
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int len = nums.size();
    int p1 = 0, p2 = 1;

    while (p2 < len) {
      if (nums[p1]) {
        ++p1;
        ++p2;
      } else {
        if (nums[p2]) {
          swap(nums[p1], nums[p2]);
          ++p1;
        }
        ++p2;
      }
    }
  }
};

int main()
{
  Solution sol;
  //vector<int> nums {1,5,5,3,1};
  //vector<int> nums {0, 1, 0, 3, 12};
  //vector<int> nums {0, 0, 0, 3, 12};
  vector<int> nums {0, 0, 1, 3, 0, 2, 0, 12};

  sol.moveZeroes(nums);

  for (const int num : nums) {
    cout << num << endl;
  }
}
