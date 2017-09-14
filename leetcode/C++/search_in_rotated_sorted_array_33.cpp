#include "common.hpp"

// 1. find the pivot point
// 2. do binary search in the corresponding sorted subarray

// Use binary search to find out the pivot point:

// time: O(logN)
// space: O(1)

class Solution {
public:
  int findPivot(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) return lo;
    if (nums[lo] < nums[hi]) return hi; // complete ordered
    int mid = (lo + hi) / 2;
    // pivot is between mid and hi-1
    if (nums[mid] > nums[hi]) return findPivot(nums, mid, hi-1);
    // pivot is between lo+1 and mid
    else return findPivot(nums, lo, mid-1);
  }

  int search(vector<int>& nums, int start, int end, int target) {
    int mid;
    while (start <= end) {
      mid = (start + end) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) start = mid + 1;
      else end = mid - 1;
    }

    return -1;
  }

  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;

    int pivot_index = findPivot(nums, 0, nums.size() - 1);
    cout << "pivot: " << pivot_index << endl;
    if (target <= nums[pivot_index] && target >= nums[0]) {
      return search(nums, 0, pivot_index, target);
    }
    return search(nums, pivot_index+1, nums.size()-1, target);
  }
};

int main()
{
  Solution sol;
  vector<int> nums {4,5,6,7,0,1,2,3};
  cout << sol.search(nums, 5) << endl;

  vector<int> nums1 {7,0,1,2,3};
  cout << sol.search(nums1, 5) << endl;
  cout << sol.search(nums1, 7) << endl;
  cout << sol.search(nums1, 0) << endl;

  vector<int> nums2 {2,3,4,5,1};
  cout << sol.search(nums2, 1) << endl;
}
