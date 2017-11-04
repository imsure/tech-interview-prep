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

// time: O(nlogn)
// space: O(n)

class Solution3 {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;

    int min_len = n+1;
    vector<int> sums (n);

    // sums is sorted!
    sums[0] = nums[0];
    for (int i = 1; i < n; ++i) sums[i] = sums[i-1] + nums[i];

    if (sums[n-1] < s) return 0;

    for (int i = 0; i < n; ++i) {
      int target = s + sums[i] - nums[i];
      auto lo = std::lower_bound(sums.begin() + i, sums.end(), target);
      if (lo != sums.end()) {
        min_len = min(min_len, (int)std::distance(sums.begin()+i, lo+1));
      }
    }

    return min_len;
  }
};

// two pointers approach: i points to the start of each subarray
// we are searching, j points to the end of the subarray. We sum
// up all the elements between i and j, as soon as the current sum >= s,
// we can update the min length and advance i by 1, also decrease
// current sum by nums[i] and continue the search.

class Solution4 {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    int min_len = n+1;

    int i = 0, j = 0, cur_sum = 0;
    while (i < n) {
      if (cur_sum < s && j < n) {
        cur_sum += nums[j++];
      } else {
        if (cur_sum >= s) min_len = min(min_len, j - i);
        cur_sum -= nums[i];
        ++i;
      }
    }

    return min_len == n+1 ? 0 : min_len;
  }
};

int main()
{
  Solution4 sol;
  vector<int> nums {2,3,1,2,4,3};
  cout << sol.minSubArrayLen(7, nums) << endl;
}
