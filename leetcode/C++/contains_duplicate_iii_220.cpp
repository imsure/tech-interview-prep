#include "common.hpp"

// set + sliding windows
//
// Linear scan the array, use a set to keep track of a sorted windows of k elements,
// when a new element x comes, find the first element in the set that is >= (x-t),
// if this element y does not exist, then move on, otherwise calculate the absolute
// difference between x and y, if difference <= t, return true, otherwise move on.

// time: O(NlogN)
// space: O(k)

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k < 0 || t < 0) return false;

    set<long> num_set;

    for (int i = 0; i < nums.size(); ++i) {
      if (num_set.size() > k) num_set.erase(nums[i - k - 1]);

      // find the first element in the set that is >= (nums[i] - t)
      auto it_lo = num_set.lower_bound((long)(nums[i]) - t);

      if (it_lo != num_set.end() && abs(*it_lo - (long)nums[i]) <= t) return true;

      num_set.insert(nums[i]);
    }

    return false;
  }
};


// Buckets
//
// Linear scan the array, maintain a window of k buckets using a HashMap. Each bucket
// is of size t+1, so [0, t] will fall into bucket 0, [t+1, 2t+1] will fall into bucket 1, etc.
//
// For any element x associated with bucket y, the elements that satisfy the almost duplicate conditions
// can be in bucket y, bucket y-1 or bucket y+1. So we only need to check these tree buckets.
//
// For each element x belongs bucket y, if bucket y already exists, return true; otherwise check
// if the distance between x and bucket y-1 and y+1 (if they exist) is <= t, if yes return true.

// time: O(N)
// space: O(k)

class Solution2 {
private:
  long getBucketLabel(long value, long sz) {
    return value >= 0 ? value / sz : value / sz - 1;
  }

public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k <= 0 || t < 0) return false;

    long bucket_size = (long)t + 1;
    unordered_map<long, long> buckets; // bucket label -> element
    for (int i = 0; i < nums.size(); ++i) {
      // in C++, -3 / 5 = 0, but we want to put -3 in bucket with label -1
      long bucket_label = getBucketLabel(nums[i], bucket_size);
      if (buckets.count(bucket_label)) return true;
      if (buckets.count(bucket_label-1) && abs(nums[i] - buckets[bucket_label-1]) <= t) return true;
      if (buckets.count(bucket_label+1) && abs(nums[i] - buckets[bucket_label+1]) <= t) return true;

      buckets[bucket_label] = nums[i];
      if (i >= k) buckets.erase(getBucketLabel(nums[i-k], bucket_size));
    }

    return false;
  }
};


int main()
{
  // vector<int> nums {0, 2147483647};
  vector<int> nums {-2147483648,-2147483647};
  Solution2 sol;
  // cout << -6 / 5 << endl;
  cout << std::boolalpha << sol.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl; // true
  // cout << std::boolalpha << sol.containsNearbyAlmostDuplicate(nums, 3, 3) << endl;
}
