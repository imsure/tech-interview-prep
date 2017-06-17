#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      index = abs(nums[i]) - 1; // index starts from 0
      if (nums[index] > 0)
        nums[index] = -nums[index];
    }

    vector<int> res {};
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) res.push_back(i+1);
    }

    return res;
  }
};

int main()
{
  vector<int> nums {4,3,2,7,8,2,3,1};
  Solution sol;
  vector<int> res = sol.findDisappearedNumbers(nums);
  for (const int num : res) {
    cout << num << endl;
  }
}
