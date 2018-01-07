#include "../common.hpp"

class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int max_num = -1, second_max = -1;
    int max_index;
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= max_num) {
        second_max = max_num;
        max_num = nums[i];
        max_index = i;
      } else if (nums[i] > second_max) {
        second_max = nums[i];
      }
    }

    if (max_num >= 2 * second_max) return max_index;
    else return -1;
  }
};

int main()
{
  Solution sol;
}
