#include "common.hpp"

// time:
// space:

struct Record {
  int count;
  int start;
  int end;

public:
  Record() : count(0), start(-1), end(-1) {}
};

class Solution {
public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, Record> records;

    int degree = 0;
    for (int i = 0; i < nums.size(); ++i) {
      degree = max(degree, ++(records[nums[i]].count));
      if (records[nums[i]].start == -1) {
        records[nums[i]].start = i;
        records[nums[i]].end = i;
      } else {
        records[nums[i]].end = i;
      }
    }

    int min_len = nums.size();
    for (auto& kv : records) {
      auto& rec = kv.second;
      if (rec.count == degree) min_len = min(min_len, rec.end - rec.start + 1);
    }

    return min_len;
  }
};


class Solution2 {
public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, Record> records;
    int degree = 0, prev_degree = 0;
    int min_len = nums.size();

    for (int i = 0; i < nums.size(); ++i) {
      auto& rec = records[nums[i]];
      prev_degree = degree;
      degree = max(degree, ++(rec.count));
      if (rec.start == -1) {
        rec.start = i;
        rec.end = i;
      } else {
        rec.end = i;
      }

      if (degree > prev_degree) min_len = nums.size();
      if (rec.count == degree) min_len = min(min_len, rec.end - rec.start + 1);
    }

    return min_len;
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums {1, 2, 2, 3, 1}; // 2
  // vector<int> nums {1,2,2,3,1,4,2}; // 6
  cout << sol.findShortestSubArray(nums) << endl;
}
