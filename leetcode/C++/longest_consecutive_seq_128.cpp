#include "common.hpp"

// Time Limit Exceeded

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> nums_set;
    int len = nums.size();
    int longest_local, longest_global = 0;
    int cur_num;

    for (int i = 0; i < len; ++i) {
      cur_num = nums[i];
      longest_local = 1;
      nums_set.insert(cur_num);
      while (nums_set.count(--cur_num)) ++longest_local;
      cur_num = nums[i];
      while (nums_set.count(++cur_num)) ++longest_local;
      longest_global = max(longest_global, longest_local);
    }

    return longest_global;
  }
};

// wrong solution

class Solution2 {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, pair<int, int>> table;
    int len = nums.size();
    int longest = 0;
    int cur_num;

    for (int i = 0; i < len; ++i) {
      table[nums[i]] = make_pair(1, 1);
      cur_num = nums[i] - 1;
      if (table.count(nums[i] - 1)) {
        table[nums[i]].first += table[nums[i] - 1].first;
        table[nums[i] - 1].second += table[nums[i]].second;
        //longest = max(longest, table[nums[i]-1].first + table[nums[i]-1].second - 1);
      }
      if (table.count(nums[i] + 1)) {
        table[nums[i]].second += table[nums[i] + 1].second;
        table[nums[i] + 1].first += table[nums[i]].first;
        //longest = max(longest, table[nums[i]+1].first + table[nums[i]+1].second - 1);
      }
      longest = max(longest, table[nums[i]].first + table[nums[i]].second - 1);
      cout << "longest: " << longest << endl;
    }

    return longest;
  }
};


class Solution3 {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;
    int max_len = 0;

    int l, r;
    for (int n : nums) {
      if (map[n]) continue; // skip duplicates

      l = map[n-1]; // len of sequence with n-1 as the boundary point
      r = map[n+1]; // len of sequence with n+1 as the boundary point
      map[n] = l + r + 1; // len of sequence that passes n
      if (l) map[n-l] = l + r + 1; // update len of sequence with n-l as the boundary point
      if (r) map[n+r] = l + r + 1; // update len of sequence with n+r as the boundary point
      max_len = max(max_len, l + r + 1);
    }

    return max_len;
  }
};

int main()
{
  Solution3 sol;
  //vector<int> nums {100,4,200,1,3,2,5,6};
  vector<int> nums {1,2,0,1};
  cout << sol.longestConsecutive(nums) << endl;
}
