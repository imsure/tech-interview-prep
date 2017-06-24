#include "common.hpp"

// Dynamic Programming
// time: O(n)
// space: O(1)
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int max_subsum_ending_at = nums[0], max_subsum_so_far = nums[0];

    for (int i = 1; i < len; ++i) {
      // The max subsum ending at position i either contains the max subsum
      // ending at position i-1 as a prefix or not.
      // (if nums[i] + max_subsum_ending_at > nums[i], then yes, else no)
      max_subsum_ending_at = max(nums[i], nums[i] + max_subsum_ending_at);
      // update max subsum seen so far as necessary
      max_subsum_so_far = max(max_subsum_so_far, max_subsum_ending_at);
    }

    return max_subsum_so_far;
  }
};

// Divide and Conquer
// time: O(nlg_n)
// space: O(1)
// why DP is better than divide-and-conquer for this problem?
class Solution2 {
private:
  // any subarray crossing the mid point contains two subarrays [i, mid] and [mid+1, j],
  // thus we just need to find max subsum left to the mid and right to the mid, then combine
  // the two.
  int _maxSubArrayCrossing(vector<int>& array, int low, int mid, int high) {
    int left_sum = numeric_limits<int>::min();
    int right_sum = numeric_limits<int>::min();
    int sum = 0;

    for (int i = mid; i >= low; --i) {
      sum += array[i];
      left_sum = max(left_sum, sum);
    }

    sum = 0;
    for (int j = mid + 1; j <= high; ++j) {
      sum += array[j];
      right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
  }

  // divide the array into two subarrays: array[low, mid] and array[mid+1, high],
  // then the max subsum is either entirely in [low, mid] or entirely in [mid+1, high],
  // or crosses the mid point. We can find max subsum of array[low, mid] and array[mid+1, high]
  // recursively since they are the subproblems that are the smaller instances of the original
  // problem.

  // the subtle part is that we need a special method to find the max subsum crossing the
  // mid point because this is not a smaller instance of the original problem.
  int _maxSubArray(vector<int>& array, int low, int high) {
    if (low >= high) return array[low];

    int mid = (high + low) / 2;
    int max_left = _maxSubArray(array, low, mid);
    int max_right = _maxSubArray(array, mid + 1, high);
    int max_cross = _maxSubArrayCrossing(array, low, mid, high);

    int max_tmp = max(max_left, max_right);
    return max(max_tmp, max_cross);
  }

public:
  int maxSubArray(vector<int>& nums) {
    return _maxSubArray(nums, 0, nums.size() - 1);
  }
};

int main()
{
  Solution sol;
  vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
  cout << sol.maxSubArray(nums) << endl;

  Solution2 sol2;
  cout << sol2.maxSubArray(nums) << endl;
}
