#include "common.hpp"


class Solution {
public:
  int findLHS(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> num2count;
    for (int num : nums) num2count[num]++;
    for (auto kv : num2count) {
      int num = kv.first;
      int count = kv.second;
      if (num2count.count(num-1)) ans = max(ans, count + num2count[num-1]);
      if (num2count.count(num+1)) ans = max(ans, count + num2count[num+1]);
    }

    return ans;
  }
};


int main()
{
  Solution sol;
  vector<int> nums {1,3,2,2,5,2,3,7};
  cout << sol.findLHS(nums) << endl;
}
