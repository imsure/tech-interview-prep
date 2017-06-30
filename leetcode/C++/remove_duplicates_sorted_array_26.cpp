#include "common.hpp"

// not an elegant solution, was thinking too much and shouldn't
// use swap, has to handle some corner cases.

// time: O(n)
// space: O(1)
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int len_orig = nums.size();

    if (len_orig < 2) return len_orig;

    int curr = 0, next = 1;
    int len_unique = 1;
    while (next < len_orig) {
      if (nums[next] != nums[curr]) {
        if (next - curr > 1) {
          std::swap(nums[curr+1], nums[next]);
        }
        ++len_unique;
        ++curr;
        ++next;
      } else {
        // move the next pointer the first element that is different with the current element
        ++next;
        while (next < len_orig && nums[next] == nums[next-1]) ++next;
        if (next < len_orig) {
          std::swap(nums[curr+1], nums[next]);
          ++curr;
          ++len_unique;
        }
        ++next;
      }
    }

    return len_unique;
  }
};

// credit: https://leetcode.com/articles/remove-duplicates-sorted-array/

// idea: two pointers. one slow pointer i initialized as 0
// and one faster pointer j initialized as 1.
// as long as nums[i] == nums[j], move j forward to skip duplicates.
// when nums[i] != nums[j], duplicate run has ended so we assign nums[j] to
// nums[i+1], i is incremented by 1 and repeat the same process until j
// reaches the end of the array.

// time: O(n)
// space: O(1)
class Solution2 {
public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();

    if (len < 2) return len;

    int i = 0, j;
    for (j = 1; j < len; ++j) {
      if (nums[i] != nums[j]) {
        ++i;
        nums[i] = nums[j];
      }
    }
    return i+1;
  }
};

int main()
{
  Solution sol;
  // vector<int> nums {2, 7, 11, 15};
  // vector<int> nums {1, 1, 1, 2, 2, 3};
  // vector<int> nums {1, 1, 1};
  vector<int> nums {1, 1, 2, 3};
  int len = sol.removeDuplicates(nums);
  cout << len << endl;
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << ", ";
  }
  cout << endl;
}
