#include "common.hpp"

class Solution {
public:
  string reverseStr(string s, int k) {
    int len = s.size();
    int i;
    for (i = 0; i + 2 * k < len; i += 2 * k) {
      std::reverse(s.begin() + i, s.begin() + i + k);
    }
    int r = len - i;
    if (r <= k) {
      std::reverse(s.begin() + i, s.end());
    } else {
      std::reverse(s.begin() + i, s.begin() + i + k);
    }

    return s;
  }
};

// more elegant and concise code
// credit: https://discuss.leetcode.com/topic/82652/one-line-c

class Solution2 {
public:
  string reverseStr(string s, int k) {
    int len = s.size();
    for (int i = 0; i < len; i += 2 * k) {
      std::reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
    }
    return s;
  }
};

int main()
{
  string s1 {"abcdefg"};
  Solution2 sol;
  cout << sol.reverseStr(s1, 2) << endl;
}
