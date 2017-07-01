#include "common.hpp"

// idea: sort the array first, for each number x from at index i, scan the
// remaining numbers from i+1 to the end, find if there exists y+z = -x, jump over
// the numbers have been scanned to ignore the duplicates.

// time: O(n^2)
// space:
class Solution {
public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int len = nums.size();

    if (len < 3) return 0;

    sort(nums.begin(), nums.end());

    int counter = 0;
    int i, front, back, three_sum;
    for (i = 0; i < len; ++i) {
      front = i + 1;
      back = len - 1;
      while (front < back) {
        three_sum = nums[i] + nums[front] + nums[back];
        if (three_sum < target) {
          counter += back - front;
          ++front;
        } else { // three_sum >= target
          --back;
        }
      }
    }

    return counter;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {-2, -1, -1, 0, 2, 3};
  // vector<int> nums {-1, 0, 1, 2, -1, -4};
  // vector<int> nums {0,0,0};
  // vector<int> nums {0,1,-5,-4,0,-4,1};
  // vector<int> nums {0,-4,-1,-4,-2,-3,2};
  // vector<int> nums {-2,-3,0,0,-2};
  // vector<int> nums {-2, 0, 1, 3};
  cout << sol.threeSumSmaller(nums, -2) << endl;
}
