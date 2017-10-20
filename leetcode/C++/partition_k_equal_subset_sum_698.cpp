#include "common.hpp"

class Solution {
private:
  bool _canPartitionKSubsets(vector<int>& nums, vector<int>& buckets, int pos, int equal_sum, int k) {
    if (pos >= nums.size()) return true;

    int val = nums[pos++]; // get the current value and advance the pointer by 1
    for (int i = 0; i < k; ++i) {
      if (buckets[i] + val <= equal_sum) {
        buckets[i] += val;
        if (_canPartitionKSubsets(nums, buckets, pos, equal_sum, k)) return true;
        buckets[i] -= val;
      }
      if (buckets[i] == 0) break;
    }

    return false;
  }

public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += nums[i];
    if (sum % k) return false;
    int equal_sum = sum / k;

    sort(nums.begin(), nums.end());
    //cout << equal_sum << ", " << nums[n-1] << endl;
    if (nums[n-1] > equal_sum) return false;
    int pos = 0;
    vector<int> buckets (k, 0);
    return _canPartitionKSubsets(nums, buckets, pos, equal_sum, k);
  }
};

class Solution2 {
private:
  bool _canPartitionKSubsets(vector<int>& nums, vector<int>& buckets, int pos, int equal_sum, int k) {
    if (pos < 0) return true;

    int val = nums[pos--]; // get the current value and advance the pointer by 1 backwards
    for (int i = 0; i < k; ++i) {
      cout << "pos: " << pos << ", val: " << val << endl;
      if (buckets[i] + val <= equal_sum) {
        buckets[i] += val;
        if (_canPartitionKSubsets(nums, buckets, pos, equal_sum, k)) return true;
        buckets[i] -= val;
      }
      for (auto v : buckets) cout << v << ", ";
      cout << endl;
      if (buckets[i] == 0) break;
    }

    return false;
  }

public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += nums[i];
    if (sum % k) return false;
    int equal_sum = sum / k;

    sort(nums.begin(), nums.end());
    if (nums[n-1] > equal_sum) return false;
    int pos = n - 1;
    while (pos >= 0 && nums[pos] == equal_sum) {
      --pos; --k;
    }

    vector<int> buckets (k, 0);
    return _canPartitionKSubsets(nums, buckets, pos, equal_sum, k);
  }
};

int main()
{
  // vector<int> nums {4, 3, 2, 3, 5, 2, 1};
  // vector<int> nums {960,3787,1951,5450,4813,752,1397,801,1990,1095,3643,8133,893,5306,8341,5246};
  // vector<int> nums {2,3,3};
  vector<int> nums {1,1,3,3};
  Solution2 sol;
  cout << sol.canPartitionKSubsets(nums, 2) << endl;
}
