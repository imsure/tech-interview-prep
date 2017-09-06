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

// Store each digits into a vector and map positions to digits.
// e.g., for num = 2736, we have [6,3,7,2] and {0:6, 1:3, 2:7, 3:2}.
// Then sort the vector: [2,3,6,7] so that we can pick up the largest digit later.
// Next, scan from the highest postion to lowest position:
// - if the highest digit is the largest digit, then update the largest digit
//   and move on to the next position
// - if not, then find out the smallest position of the largest digit and swap the two
//   digits
// Finally, recontruct the result from the map.

// improved code quality

class Solution2 {
public:
  int maximumSwap(int num) {
    if (num < 10) return num;

    unordered_map<int, int> pos2digit;
    int d, pos = 0;
    vector<int> digits;
    while (num) {
      d = num - 10 * (num/10);
      digits.push_back(d);
      pos2digit[pos++] = d;
      num = num / 10;
    }

    sort(digits.begin(), digits.end());
    int cur_max = digits[pos-1];
    for (int i = pos-1; i >= 0; --i) {
      if (pos2digit[i] != cur_max) {
        d = pos2digit[i];
        pos2digit[i] = cur_max;
        int smallest_pos = numeric_limits<int>::max();
        for (auto& kv : pos2digit) {
          if (kv.second == cur_max) {
            smallest_pos = min(smallest_pos, kv.first);
          }
        }
        pos2digit[smallest_pos] = d;
        break;
      } else {
        cur_max = digits[i-1];
      }
    }

    int ret = 0;
    for (int i = 0; i < pos; ++i) {
      ret += pos2digit[i] * pow(10, i);
    }

    return ret;
  }
};

int main()
{
  Solution2 sol;
  cout << sol.maximumSwap(2993) << endl;
}
