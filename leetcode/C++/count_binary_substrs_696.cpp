#include "common.hpp"

// Linear scan the input string, count the # (n1) of 0's(or 1's) followed by
// # (n2) of 1's (or 0's). There will be min(n1, n2) binary substrings, then advance
// the pointer by n1 and repeat the same process until done.

// time:
// space:

class Solution {
public:
  int countBinarySubstrings(string s) {
    int n1, n2, i = 0, count = 0;
    while (i < s.size()) {
      char cur = s[i];
      n1 = 0;
      while (i < s.size() && s[i] == cur) {
        ++n1;
        ++i;
      }
      cur = s[i];
      n2 = 0;
      while (i < s.size() && s[i] == cur) {
        ++n2;
        ++i;
      }

      count += min(n1, n2);
      i -= n2;
    }

    return count;
  }
};


// improved efficiency

// time: O(N)
// space: O(1)

class Solution2 {
public:
  int countBinarySubstrings(string s) {
    int n1, n2, i = 0, count = 0;
    char cur = s[i];
    n1 = 0;
    while (i < s.size() && s[i] == cur) {
      ++n1;
      ++i;
    }

    while (i < s.size()) {
      cur = s[i];
      n2 = 0;
      while (i < s.size() && s[i] == cur) {
        ++n2;
        ++i;
      }

      count += min(n1, n2);
      n1 = n2;
    }

    return count;
  }
};


int main()
{
  Solution2 sol;
  cout << sol.countBinarySubstrings("00110011") << endl; // 6
  cout << sol.countBinarySubstrings("10101") << endl; // 6
}
