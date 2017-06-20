#include "common.hpp"

// time:
// space:
class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> char_count;
    for (const char c : s) {
      if (char_count.find(c) == char_count.end()) {
        char_count[c] = 1;
      } else {
        char_count[c] += 1;
      }
    }

    int len = s.size();
    for (int i = 0; i < len; ++i) {
      if (char_count[s[i]] == 1) return i;
    }

    return -1;
  }
};

int main()
{
  Solution sol;
  cout << sol.firstUniqChar("leetcode") << endl;
  cout << sol.firstUniqChar("loveleetcode") << endl;
}
