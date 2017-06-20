#include "common.hpp"

// time:
// space:
class Solution {
private:
  bool checkEqual(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len-1; ++i) {
      if (nums[i] != nums[i+1]) return false;
    }

    return true;
  }

public:
  int minMoves(vector<int>& nums) {
    int len = nums.size();
    int max_elem = numeric_limits<int>::min(), max_elem_index;
    for (int i = 0; i < len; ++i) {
      if (max_elem < nums[i]) {
        max_elem = nums[i];
        max_elem_index = i;
      }
    }

    int move_count = 0;
    int max_elem_tmp, max_elem_index_tmp;
    while (!checkEqual(nums)) {
      max_elem_tmp = max_elem;
      max_elem_index_tmp = max_elem_index;
      // make one move
      for (int i = 0; i < len; ++i) {
        if (i != max_elem_index) {
          nums[i] += 1;
          if (nums[i] > max_elem) {
            max_elem_tmp = nums[i];
            max_elem_index_tmp = i;
          }
        }
      }
      max_elem = max_elem_tmp;
      max_elem_index = max_elem_index_tmp;

      ++move_count;
    }

    return move_count;
  }
};


class Solution2 {
public:
  int minMoves(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int min_val = numeric_limits<int>::max();
    int sum = 0;
    for (const int num : nums) {
      sum += num;
      min_val = min(min_val, num);
    }

    return sum - nums.size() * min_val;
  }
};

int main()
{
  Solution2 sol;
  vector<int> nums {1,2,3};
  cout << sol.minMoves(nums) << endl;
  vector<int> nums1 {1,3,5,6};
  cout << sol.minMoves(nums1) << endl;
}
