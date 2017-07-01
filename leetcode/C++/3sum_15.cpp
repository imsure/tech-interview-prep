#include "common.hpp"

// wrong and ugly code! abandoned

// time: O(n^2)
// space:
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> results {};
    if (len < 3) return results;

    unordered_map<int, vector<pair<int, int>>> group_by_pairsum;

    sort(nums.begin(), nums.end());

    int i, j;
    int prev_num_i = numeric_limits<int>::max(), prev_num_j = numeric_limits<int>::max();
    for (i = 0; i < len; ++i) {
      if (nums[i] == prev_num_i) {
        continue;
      }
      for (j = i + 1; j < len; ++j) {
        if (nums[j] == prev_num_j) {
          continue;
        }
        group_by_pairsum[nums[i] + nums[j]].emplace_back(make_pair(nums[i], nums[j]));
        prev_num_j = nums[j];
      }
      prev_num_i = nums[i];
    }

    // cout << "map:\n";
    // for (const auto& keyval : group_by_pairsum) {
    //   cout << keyval.first << ':';
    //   for (const auto& item : keyval.second) {
    //     cout << '(' << item.first << ',' << item.second << ')';
    //   }
    //   cout << endl;
    // }
    // cout << "end of map\n";

    int prev_n = numeric_limits<int>::max();
    for (int i = 0; i < len; ++i) {
      int n = nums[i];
      if (prev_n == n) continue;
      if (group_by_pairsum.find(-n) != group_by_pairsum.end()) {
        for (const auto& item : group_by_pairsum[-n]) {
          if ((n == item.first || n == item.second) && (n != nums[i+1])) {
            continue;
          }

          // remove duplicated triplets
          bool has_duplicate = false;
          for (const auto& res : results) {
            if ((item.first == res[0] || item.first == res[1] || item.first == res[2]) &&
                (item.second == res[0] || item.second == res[1] || item.second == res[2])) {
              has_duplicate = true;
              break;
            }
          }
          if (!has_duplicate)
            results.emplace_back(vector<int> {n, item.first, item.second});
        }
      }
      prev_n = n;
    }

    int zero_count = 0;
    for (const int n : nums) {
      if (n == 0) ++zero_count;
    }

    if (zero_count >= 3) {
      bool has_duplicate = false;
      for (const auto& res : results) {
        if ((0 == res[0] && 0 == res[1]) || (0 == res[0] && 0 == res[2]) ||
            (0 == res[2] && 0 == res[1])) {
          has_duplicate = true;
          break;
        }
      }
      if (!has_duplicate)
        results.emplace_back(vector<int> {0,0,0});
    }

    return results;
  }
};


// idea: sort the array first, then for each negative value x,
// add n1 with each positive value y, then binary searching (x+y), if found,
// add (x, y, -(x+y)) to result. skip any dupcliated x and y during traversal.

// time: O(n^2 * log(n))
// space:
class Solution2 {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> results {};
    int len = nums.size();
    if (len < 3) return results;

    sort(nums.begin(), nums.end());
    int start = 0, end = len - 1;
    int twosum;
    int prev_start = numeric_limits<int>::min(), prev_end = numeric_limits<int>::min();
    while (start < len && nums[start] < 0) {
      if (prev_start == nums[start]) {
        ++start;
        continue;
      }

      prev_end = numeric_limits<int>::min(); // reset
      while (nums[end] > 0) {
        if (prev_end == nums[end]) {
          --end;
          continue;
        }

        twosum = nums[start] + nums[end];
        if (std::binary_search(nums.begin() + start + 1, nums.begin() + end, -twosum)) {
          results.emplace_back(vector<int> {nums[start], nums[end], -twosum});
        }

        prev_end = nums[end];
        --end;
      }

      prev_start = nums[start];
      ++start;
      end = len - 1;
    }

    if (start < len && nums[start] == 0) {
      if (start + 2 < len && nums[start+1] == 0 && nums[start+2] == 0)
        results.emplace_back(vector<int> {0,0,0});
    }

    return results;
  }
};

// credit: https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments
// idea: sort the array first, for each number x from at index i, scan the
// remaining numbers from i+1 to the end, find if there exists y+z = -x, jump over
// the numbers have been scanned to ignore the duplicates.

// time: O(n^2)
// space:
class Solution3 {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result {};
    int len = nums.size();

    if (len < 3) return result;

    std::sort(nums.begin(), nums.end());

    int i = 0, front, back, target = -nums[i];
    while (i < len && target >= 0) {
      front = i + 1;
      back = len - 1;

      while (front < back) {
        int twosum = nums[front] + nums[back];
        if (twosum < target) ++front;
        else if (twosum > target) --back;
        else {
          vector<int> triplet (3, 0);
          triplet[0] = nums[i];
          triplet[1] = nums[front];
          triplet[2] = nums[back];
          result.emplace_back(triplet);

          // skip duplicates
          while (front < back && nums[++front] == triplet[1]) ;
          while (front < back && nums[--back] == triplet[2]) ;
        }
      }
      // skip duplicates
      while (i + 1 < len && nums[i+1] == nums[i]) ++i;
      i += 1; // move i to the next value
      target = -nums[i]; // update target
    }

    return result;
  }
};

int main()
{
  Solution3 sol;
  vector<int> nums {-2, -1, -1, 0, 2, 3};
  // vector<int> nums {-1, 0, 1, 2, -1, -4};
  // vector<int> nums {0,0,0};
  // vector<int> nums {0,1,-5,-4,0,-4,1};
  // vector<int> nums {0,-4,-1,-4,-2,-3,2};
  // vector<int> nums {-2,-3,0,0,-2};
  vector<vector<int>> results = sol.threeSum(nums);
  for (const auto& res : results) {
    cout << res[0] << ", " << res[1] << ", " << res[2] << endl;
  }
}
