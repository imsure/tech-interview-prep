#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int len1 = nums1.size(), len2 = nums2.size();
    int i = 0, j = 0;
    vector<int> res;
    while (i < len1 && j < len2) {
      if (nums1[i] < nums2[j]) {
        ++i;
      } else if (nums2[j] < nums1[i]) {
        ++j;
      } else {
        if (res.empty()) {
          res.push_back(nums1[i]);
        } else if (!res.empty() && nums1[i] != res[res.size() - 1]) {
          res.push_back(nums1[i]);
        }
        ++i;
        ++j;
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 {1,5,5,3,1};
  vector<int> nums2 {5,3};
  vector<int> res = sol.intersection(nums1, nums2);
  for (const int num : res) {
    cout << num << endl;
  }
}
