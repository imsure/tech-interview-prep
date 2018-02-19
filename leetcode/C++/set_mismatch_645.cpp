#include "common.hpp"


// HashMap

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    unordered_map<int, int> num2count;
    vector<int> ans;
    for (int num : nums) {
      num2count[num]++;
      if (num2count[num] == 2) ans.push_back(num);
    }

    for (int i = 1; i <= nums.size(); ++i) {
      if (!num2count.count(i)) {
        ans.push_back(i);
        break;
      }
    }

    return ans;
  }
};


// Extra array + xor

class Solution2 {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> table (n, -1), ans;
    for (int i = 0; i < n; ++i) table[nums[i] - 1] = nums[i];

    for (int i = 0; i < n; ++i) {
      if (table[nums[i] - 1] == 0) {
        ans.push_back(nums[i]);
        break;
      }
      table[nums[i] - 1] ^= nums[i];
    }

    for (int i = 0; i < n; ++i) {
      if (table[i] == -1) {
        ans.push_back(i+1);
        break;
      }
    }

    return ans;
  }
};


// using array as map

class Solution3 {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> table (n + 1, 0), ans (2, 0);
    for (int i = 0; i < n; ++i) table[nums[i]]++;

    for (int i = 1; i <= n; ++i) {
      if (table[i] == 0) ans[1] = i;
      if (table[i] == 2) ans[0] = i;
    }

    return ans;
  }
};


int main()
{
  Solution3 sol;
  vector<int> nums = {1, 2, 2, 4};
  auto res = sol.findErrorNums(nums);
  cout << res[0] << ',' << res[1] << endl;
}
