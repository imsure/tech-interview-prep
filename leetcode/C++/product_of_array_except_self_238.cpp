#include "common.hpp"

// time:
// space:

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prod_before (n, 1); // product of nums before i (0 <= i < n)
    vector<int> prod_after (n, 1); // product of nums after i (0 <= i < n)

    for (int i = 0; i < n-1; ++i) {
      prod_before[i+1] = prod_before[i] * nums[i];
    }

    for (int i = n-2; i >= 0; --i) {
      prod_after[i] = prod_after[i+1] * nums[i+1];
    }

    vector<int> ans (n, 1);
    for (int i = 0; i < n; ++i) {
      ans[i] = prod_before[i] * prod_after[i];
    }

    return ans;
  }
};

int main()
{
  vector<int> nums {1,2,3,4};
  Solution sol;
  vector<int> res = sol.productExceptSelf(nums);
  for (auto n : res) {
    cout << n << endl;
  }
}
