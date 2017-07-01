#include "common.hpp"

// idea: sort the array first, use three pointers first, second and third.
// first is used to lock a position (from 0 to len-1), second starts from first + 1,
// moving forward, and third starts at position len-1 moving backwords.
// if nums[first]+nums[second]+nums[third] < target, we know we need to move second
// forward by 1 to increase the sum, if nums[first]+nums[second]+nums[third] < target,
// we move thrid backward by 1 to decrease the sum, make it closer to target, if sum
// is zero, return immediately.

// time: O(n^2)
// space:
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    int result = 0;

    if (len < 3) {
      for (int  i = 0; i < len; ++i) result += nums[i];
      return result;
    }

    sort(nums.begin(), nums.end());

    int distant = numeric_limits<int>::max();
    int i, front, back, three_sum, curr_distant;
    for (i = 0; i < len; ++i) {
      front = i + 1;
      back = len - 1;
      while (front < back) {
        three_sum = nums[i] + nums[front] + nums[back];
        curr_distant = std::abs(three_sum - target);
        if (curr_distant < distant) {
          distant = curr_distant;
          result = three_sum;
        }
        if (three_sum < target) {
          ++front;
        } else if (three_sum > target) { // three_sum >= target
          --back;
        } else { // three_sum = target
          return three_sum;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {-1, 2, 1, -4};
  // vector<int> nums {-1, 0, 1, 2, -1, -4};
  // vector<int> nums {0,0,0};
  // vector<int> nums {0,1,-5,-4,0,-4,1};
  // vector<int> nums {0,-4,-1,-4,-2,-3,2};
  // vector<int> nums {-2,-3,0,0,-2};
  // vector<int> nums {-2, 0, 1, 3};
  cout << sol.threeSumClosest(nums, -4) << endl;
}
