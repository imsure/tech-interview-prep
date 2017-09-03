#include "../common.hpp"

// 670. Maximum Swap My SubmissionsBack to Contest
// User Accepted: 119
// User Tried: 168
// Total Accepted: 119
// Total Submissions: 234
// Difficulty: Medium
// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number.
// Return the maximum valued number you could get.

//   Example 1:
//   Input: 2736
//   Output: 7236
//   Explanation: Swap the number 2 and the number 7.
//   Example 2:
//   Input: 9973
//   Output: 9973
//   Explanation: No swap.
//   Note:
//   The given number is in the range [0, 10^8]

class Solution {
public:
  int maximumSwap(int num) {
    if (num < 10) return num;

    unordered_map<int, int> map;
    int n = num, d, index = 0;
    vector<int> digits;
    while (n) {
      d = n - 10 * (n/10);
      digits.push_back(d);
      map[index++] = d;
      n = n / 10;
    }

    sort(digits.begin(), digits.end());
    int cur_max = digits[index-1];
    for (int i = index-1; i >= 0; --i) {
      if (map[i] != cur_max) {
        d = map[i];
        map[i] = cur_max;
        int smallest_index = numeric_limits<int>::max();
        for (auto& kv : map) {
          if (kv.second == cur_max) {
            smallest_index = min(smallest_index, kv.first);
          }
        }
        map[smallest_index] = d;
        break;
      } else {
        cur_max = digits[i-1];
      }
    }

    int sum = 0;
    for (int i = 0; i < index; ++i) {
      sum += map[i] * pow(10, i);
    }

    return sum;
  }
};

int main()
{
  Solution sol;
  cout << sol.maximumSwap(2993) << endl;
}
