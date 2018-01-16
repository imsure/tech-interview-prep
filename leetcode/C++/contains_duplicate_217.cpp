#include "common.hpp"

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> nums_set;
    for (int num : nums) {
      if (nums_set.count(num)) return true;
      nums_set.insert(num);
    }

    return false;
  }
};

int main()
{
  Solution sol;
}
