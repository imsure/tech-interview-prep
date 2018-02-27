#include "common.hpp"

// time: O(nk)
// TLE

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double max_avg = numeric_limits<double>::lowest();
    int n = nums.size();
    double sum = 0;
    for (int i = 0; i <= n - k; ++i) {
      for (int j = i; j < i + k; ++j) sum += nums[j];
      max_avg = max(max_avg, sum / k);
      sum = 0;
    }

    return max_avg;
  }
};


class Solution2 {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double max_avg = numeric_limits<double>::lowest();
    int n = nums.size();
    double sum = 0;
    for (int i = 0; i <= n - k; ++i) {
      if (i == 0) for (int j = 0; j < k; ++j) sum += nums[j];
      else {
        sum -= nums[i-1];
        sum += nums[i+k-1];
      }
      max_avg = max(max_avg, sum / k);
    }

    return max_avg;
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums {1,12,-5,-6,50,3};
  cout << sol.findMaxAverage(nums, 4) << endl;

  vector<int> nums2 {-1};
  cout << sol.findMaxAverage(nums2, 1) << endl;
}
