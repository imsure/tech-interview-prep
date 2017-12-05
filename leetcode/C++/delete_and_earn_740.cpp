/**
 * Delete and Earn:
 *
 * Given an array of n integers called 'elements', we can perform operations on the array,
 * in each operation, we pick an elements[i] and delete it to earn elements[i] points, we
 * also have to delete any elements equals to elements[i]-1 or elements[i]+1.
 *
 * Your task is to return a long integer denoting the maximum number of points we can earn
 * by applying such operations.
 *
 * e.g., elements = [3,4,2]
 * return: 6
 */

#include "../C++/common.hpp"

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int max_points = 0;
    int n = nums.size();
    if (!n) return max_points;

    std::sort(nums.begin(), nums.end());

    int prev_elem = 0;
    int prev_points = 0;
    int prev_prev_elem = 0;
    int prev_prev_points = 0;

    int i = 0;
    while (i < n) {
      int cur_elem = nums[i];
      int cur_elem_sum = cur_elem;
      while (i+1 < n && nums[i+1] == cur_elem) {
        ++i;
        cur_elem_sum += nums[i];
      }

      // for the current element, we have two options: either delete it or not,
      // we pick the max points can be collected between these two options.
      if (cur_elem == prev_elem + 1) {
        max_points = max(cur_elem_sum + prev_prev_points, prev_points);
      } else {
        max_points += cur_elem_sum;
      }

      prev_prev_elem = prev_elem;
      prev_elem = cur_elem;
      prev_prev_points = prev_points;
      prev_points = max_points;

      ++i;
    }

    return max_points;
  }
};


int main()
{
  Solution sol;
  // vector<int> elements {3, 4, 2}; // 6
  // vector<int> elements {2, 2, 1, 1, 1, 1, 3}; // 7
  // vector<int> elements {3, 5, 1}; // 9
  // vector<int> elements {1,1,1,2}; // 3
  // vector<int> elements {1,2}; // 2
  // vector<int> elements {3}; // 3
  // vector<int> elements {}; // 0
  // vector<int> elements {1,2,3,4,5}; // 9
  // vector<int> elements {1,2,3,4,5,5,6}; // 14
  // vector<int> elements {3, 6, 9, 1, 2, 4, 5, 5, 12, 7, 8, 8, 8, 9}; // 51
  vector<int> elements {2,2,3,3,3,4}; // 9
  cout << sol.deleteAndEarn(elements) << endl;
}
