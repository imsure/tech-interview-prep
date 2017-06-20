#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> indices;
    int index = 1;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
      if (binary_search(it + 1, numbers.end(), target - *it)) {
        indices.push_back(index);
        break;
      }
      ++index;
    }

    int len = numbers.size();
    for (int i = 0; i < len; ++i) {
      if (numbers[i] == (target - numbers[index - 1]) && i > (index-1)) {
        indices.push_back(i+1);
        break;
      }
    }

    return indices;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {2, 7, 11, 15};
  vector<int> res = sol.twoSum(nums, 9);
  cout << res[0] << ", " << res[1] << endl;
}
