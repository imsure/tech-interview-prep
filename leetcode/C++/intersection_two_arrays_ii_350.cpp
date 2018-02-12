#include "common.hpp"


// HashMap

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map1, map2;
    for (int num : nums1) map1[num]++;
    for (int num : nums2) map2[num]++;

    vector<int> ans;
    for (auto& kv : map1) {
      int num = kv.first;
      int count = kv.second;
      if (map2.count(num)) {
        int len = min(count, map2[num]);
        for (int i = 0; i < len; ++i) ans.push_back(num);
      }
    }

    return ans;
  }
};


// Sort + Two pointers

class Solution2 {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;

    int p1 = 0, p2 = 0;
    while (p1 < nums1.size() && p2 < nums2.size()) {
      if (nums1[p1] < nums2[p2]) ++p1;
      else if (nums1[p1] > nums2[p2]) ++p2;
      else {
        ans.push_back(nums1[p1]);
        ++p1;
        ++p2;
      }
    }

    return ans;
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums1 {1,2,2,1}, nums2 {2,2};
  auto ret = sol.intersect(nums1, nums2);
  for (int n : ret) cout << n << ' ';
  cout << '\n';
}
