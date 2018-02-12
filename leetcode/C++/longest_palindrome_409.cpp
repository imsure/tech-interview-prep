#include "common.hpp"


class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> groups;
    for (char c : s) groups[c]++;

    int len = 0;
    bool has_odd = false;
    for (auto kv : groups) {
      int count = kv.second;
      if (count % 2) {
        len += count - 1;
        has_odd = true;
      }
      else len += count;
    }

    if (has_odd) len++;

    return len;
  }
};


int main()
{
  Solution sol;
  cout << sol.longestPalindrome("abccccdd") << endl;
}
