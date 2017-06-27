#include "common.hpp"

// sort the array first, then just sum up the elements with even indexes.
// the idea is to pair elements up in way so as to minimize the losses incurred,
// thus we should pair two elements with minimum difference between them.

// time: O(nlog(n))
// space: O(1)
class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }

    return sum;
  }
};

// A more clever solution using a hashtable as mentioned here:
// https://leetcode.com/articles/array-partitioning-i/
// hashtable[i] maps the number (i - 10000) to its frequency in the input array.
// thus after building the hashtable, we can traverse the hashtable in
// ascending order. The tricky part is that we need an extra flag to indicate whether
// or not the frequency of the previous traversed element is odd or not to handle
// the case like [1,1,1,2,2,2] where the sum = 1 + 1 + 2, we don't want to sum 2 for
// twice since one of 2's was paired with a 1.

// time: O(n)
// space: O(n)
class Solution2 {
public:
  int arrayPairSum(vector<int>& nums) {
    vector<int> hashtable (20001, 0);

    for (const int num : nums) {
      hashtable[num + 10000] += 1;
    }

    int sum = 0;
    bool flag = false;
    for (int i = 0; i < 20001; ++i) {
      if (flag && hashtable[i] > 0) {
        hashtable[i]--;
        flag = false;
      }
      if (hashtable[i] > 0) {
        sum += std::ceil(hashtable[i] / 2.0) * (i - 10000);
        if (hashtable[i] % 2) flag = true;
      }
    }

    return sum;
  }
};

int main()
{
  vector<int> nums {1,4,3,2};
  Solution sol;
  //cout << sol.arrayPairSum(nums) << endl;

  vector<int> nums2 {1,4,3,2,5,6};
  //cout << sol.arrayPairSum(nums2) << endl;

  Solution2 sol2;
  cout << sol2.arrayPairSum(nums) << endl;
  cout << sol2.arrayPairSum(nums2) << endl;

}
