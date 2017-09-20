#include "common.hpp"

// Find all the subsets of A[1...n]:
// - isolate A[1]
// - Find all the subsets of A[2...n] as B
// - Let C = all the subsets in B augmented with A[1]
// - return B and C

// unfolding the recursive calls:
// input: [1,2,3]
//   recSubsets([1,2,3], 0, res)
//             |
//             |isolate [1],
//             |res: ([], [3], [2], [2,3]) -> ([], [3], [2], [2,3], [1], [1,2], [1,3], [1,2,3])
//             |
//   recSubsets([1,2,3], 1, res)
//             |
//             |isolate [2],
//             |res: ([], [3]) -> ([], [3], [2], [2,3])
//             |
//   recSubsets([1,2,3], 2, res)
//             |
//             |isolate [3],
//             |res: ([]) -> ([], [3])
//             |
//   recSubsets([1,2,3], 3, res)
//             |
//             |no more element to isolate, push [] to res and return
//             |
// suppose input size is n, then there are total n recursive calls, for each recursive call
// from bottom to top, we need 2^0 + 2^1 + ... + 2^(n-1) = 2^n - 1. Thus the time complexity
// is O(2^n) since this is an exhuastive search algorithm. This also matches with the size of
// power set which is 2^n.

// time: O(2^n)
// space: O(1)

class Solution {
private:
  void recSubsets(vector<int>& nums, int start, vector<vector<int>>& res) {
    if (start >= nums.size()) {
      res.push_back(vector<int>()); // empty set
      return;
    }

    int isolated_num = nums[start];
    recSubsets(nums, start+1, res);
    int cur_sz = res.size();
    for (int i = 0; i < cur_sz; ++i) {
      vector<int> new_set(res[i]);
      new_set.push_back(isolated_num);
      res.push_back(new_set);
    }
  }

public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    recSubsets(nums, 0, res);
    return res;
  }
};


// another way of doing exhuastive search:
// each time isolate the last element from the rest of the input,
// then recursively find subsets that contains this element and subsets that do not contain this element
// until we've exhausted all elements.

// This thought process results in more easy-to-understand code and also make it
// easier to analyze time complexity. (since each time we branch out two recursively calls,
// and recursion goes to depth of n, so time complexity is O(2^n)).

class Solution2 {
private:
  void recSubsets(vector<int> sofar, vector<int> rest, vector<vector<int>>& res) {
    if (rest.empty()) {
      res.push_back(sofar);
      return;
    }

    int last_elem = rest[rest.size()-1];
    rest.pop_back();
    vector<int> sofar2 (sofar);
    sofar2.push_back(last_elem);
    recSubsets(sofar2, rest, res);
    recSubsets(sofar, rest, res);
  }

public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    recSubsets(vector<int>(), nums, res);
    return res;
  }
};


// iterative solution:

class Solution3 {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs (1, vector<int>());
    vector<int> sub;

    for (int i = 0; i < nums.size(); ++i) {
      int n = subs.size();
      for (int j = 0; j < n; ++j) {
        subs.push_back(subs[j]);
        subs.back().push_back(nums[i]);
      }
    }

    return subs;
  }
};

int main()
{
  vector<int> nums {1,2,3};
  Solution sol;
  vector<vector<int>> res = sol.subsets(nums);
  for (auto& set : res) {
    for (auto i : set) {
      cout << i << ',';
    }
    cout << '\n';
  }
}
