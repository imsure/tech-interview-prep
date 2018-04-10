#include "common.hpp"

// Two pointer + Merge from end

// since nums1 has enough space to hold additional elements from nums2,
// and two arrays are already sorted, we can merge from the end of the two
// arrays. Start filling nums1 from the end and move backwards until the start of
// nums1 reached.


class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p3 = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
      int next;
      if (nums1[p1] >= nums2[p2]) {
        next = nums1[p1];
        --p1;
      } else {
        next = nums2[p2];
        --p2;
      }
      nums1[p3--] = next;
    }

    while (p2 >= 0) nums1[p3--] = nums2[p2--];
  }
};


int main()
{
  Solution sol;
  // vector<int> nums1 {1, 3, 5, 0, 0, 0};
  // vector<int> nums2 {2, 4, 6};
  vector<int> nums1 {4, 5, 6, 0, 0, 0};
  vector<int> nums2 {1, 2, 3};
  sol.merge(nums1, 3, nums2, 3);
  for (int n : nums1) cout << n << '\t';
  cout << endl;
}
