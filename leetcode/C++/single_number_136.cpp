#include "common.hpp"

// time:
// space:
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int single = 0;
    for (const int num : nums) {
      single ^= num;
    }
    return single;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {1,5,5,3,1};
  cout << sol.singleNumber(nums) << endl;
}
