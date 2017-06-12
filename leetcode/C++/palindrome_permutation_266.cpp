#include "common.hpp"

// time:
// space:
class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> group_by_char;
    for (const char c : s) {
      if (group_by_char.find(c) == group_by_char.end()) {
        group_by_char[c] = 1;
      } else {
        group_by_char[c] += 1;
      }
    }

    int odd_count = 0;
    for (const auto& keyval : group_by_char) {
      if (keyval.second % 2) ++odd_count;
      if (odd_count > 1) return false;
    }
    return true;
  }
};

int main()
{
  Solution sol;
  cout << sol.canPermutePalindrome("aab") << endl;
  cout << sol.canPermutePalindrome("code") << endl;
  cout << sol.canPermutePalindrome("carerac") << endl;
}
