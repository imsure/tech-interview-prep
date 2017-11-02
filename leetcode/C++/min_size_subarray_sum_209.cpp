#include "common.hpp"

// Brute force: passed with 209ms runtime

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();

    int min_len = n+1;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        if (sum >= s) {
          min_len = min(min_len, j-i+1);
          break;
        }
      }
    }

    return min_len == n+1 ? 0 : min_len;
  }
};

// Brute force: memorize sum ends at each position, passed with 276ms runtime

class Solution2 {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;

    int min_len = n+1;
    vector<int> sums (n);

    sums[0] = nums[0];
    for (int i = 1; i < n; ++i) sums[i] += sums[i-1] + nums[i];

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (sums[j] - sums[i] + nums[i] >= s) {
          min_len = min(min_len, j-i+1);
          break;
        }
      }
    }

    return min_len == n+1 ? 0 : min_len;
  }
};


class Solution3 {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;

    int min_len = n+1;
  }
};

int main()
{
  Solution2 sol;
  vector<int> nums {2,3,1,2,4,3};
  cout << sol.minSubArrayLen(7, nums) << endl;
}
