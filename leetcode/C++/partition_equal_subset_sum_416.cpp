#include "common.hpp"

// DP approach
// suppose there are n nums and sum of nums is even and target is sum/2.
// Let table T[0...n][0...target] be filled with boolean values and
// T[i][s] = true means that there is a subset of nums[1...i] with total sum
// equals to s. Thus as long as we can find for any i, T[i][target] = true, we return true,
// otherwise return false.

// T[i][s] = true iff (T[i-1][s] = true) or (T[i-1][s-nums[i]] = true), by default its false

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += nums[i];

    if (sum % 2) return false;

    int target = sum / 2;
    vector<vector<bool>> T (n+1, vector<bool>(target+1, false));
    for (int i = 0; i <= n; ++i) T[i][0] = true; // sum of empty set is 0

    // fill table row-wise
    for (int i = 1; i <= n; ++i) {
      for (int s = 1; s <= target; ++s) {
        if (T[i-1][s]) T[i][s] = true;
        else if (s - nums[i-1] >= 0 && T[i-1][s - nums[i-1]]) T[i][s] = true;

        if (s == target && T[i][s]) return true;
      }
    }

    return false;
  }
};


// Backtracking

class Solution2 {
private:
  bool search(vector<int>& nums, int start, int target, int curSum) {
    if (curSum == target) return true;

    for (int i = start; i < nums.size(); ++i) {
      if (nums[i] > target) return false; // no way to put nums[i] into any subset with sum == target

      if (curSum + nums[i] <= target) {
        if (search(nums, i+1, target, curSum + nums[i])) return true;
      }
    }

    return false;
  }

public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += nums[i];

    if (sum % 2) return false;

    int target = sum / 2;
    // sorting the array would significant boost the performance the backtracking
    sort(nums.rbegin(), nums.rend());

    // search if there is any way to sum a subset of nums to target
    return search(nums, 0, target, 0);
  }
};


int main()
{
  vector<int> nums0 {1, 5, 11, 5}; // true
  vector<int> nums1 {2, 5, 11, 5}; // false
  vector<int> nums2 {3, 7, 5, 7}; // false
  Solution2 sol;
  cout << sol.canPartition(nums0) << endl;
  cout << sol.canPartition(nums1) << endl;
  cout << sol.canPartition(nums2) << endl;
}
