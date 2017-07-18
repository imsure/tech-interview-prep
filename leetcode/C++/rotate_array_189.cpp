#include "common.hpp"

// time: O(n)
// space: O(k)

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    stack<int> tmp;

    for (int i = n - 1; i >= n - k; --i) {
      tmp.push(nums[i]);
    }

    for (int i = n - k - 1; i >= 0; --i) {
      nums[i + k] = nums[i];
    }

    for (int i = 0; i < k; ++i) {
      nums[i] = tmp.top();
      tmp.pop();
    }
  }
};

// time: O(n)
// space: O(1)

// in place rotation: each time place m = min(k, n-k) elements
// to the right positions by switching the last m elements in the
// subarray [1...n-k] with the last m elements in the subarray[n-k+1, n].
// then the problem has been reduced to ratate the subarray[0, max(k, n-k)]
// where n = max(k, n-k) and k = 2k-n (if k > n - k) or k = k (if n - k > k)

class Solution2 {
private:
  void _rotate(vector<int>& nums, int n, int k) {
    if (n <= 1 || k <= 0 || n == k) return; // base case

    int m = min(k, n - k);
    for (int i = 0; i < m; ++i) {
      swap(nums[n-k-1-i], nums[n-1-i]);
    }
    int _n = n; // backup
    n = max(k, n - k);
    k > _n - k ? k = 2 * k - _n : k = k;

    for (const int num : nums) {
      cout << num << ',';
    }
    cout << endl;
    cout << "n = " << n << ", k = " << k << endl;

    _rotate(nums, n, k);
  }

public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    _rotate(nums, n, k);
  }
};

// use vector::insert and vector::resize, more concise code but less efficient

class Solution3 {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    nums.insert(nums.begin(), nums.begin() + n - k, nums.end());
    nums.resize(n);
  }
};

int main()
{
  Solution3 sol;
  vector<int> nums1 {1,2,3,4,5,6};
  sol.rotate(nums1, 2);
  for (const int num : nums1) {
    cout << num << ',';
  }
  cout << endl;
}
