#include "common.hpp"

// O(N^2) brute force approach. Time Limit Exceeded

class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int max_size = numeric_limits<int>::min();
    int N = nums.size();
    int k, next_index, curr_size;
    for (k = 0; k < N; ++k) {
      next_index = k;
      curr_size = 0;
      do {
        next_index = nums[next_index];
        ++curr_size;
      } while (next_index != k);
      max_size = max(max_size, curr_size);
    }

    return max_size;
  }
};

// idea: use an ordered set to store the visited values and skip the values
// they've been visited.

// time: O(n)
// space: O(n)

class Solution2 {
public:
  int arrayNesting(vector<int>& nums) {
    int max_size = numeric_limits<int>::min();
    int N = nums.size();
    int k, next_index, curr_size;
    unordered_set<int> visited;
    for (k = 0; k < N; ++k) {
      next_index = k;
      curr_size = 0;
      while (visited.count(next_index) == 0) {
        ++curr_size;
        visited.insert(next_index);
        next_index = nums[next_index];
      }
      max_size = max(max_size, curr_size);
    }

    return max_size;
  }
};

int main()
{
  Solution2 sol;
  vector<int> nums {5,4,0,3,1,6,2};
  cout << sol.arrayNesting(nums) << endl;
}
