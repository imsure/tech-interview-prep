#include "common.hpp"

// time: O(n)
// space: O(1)

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() == 0) return true;
    unordered_map<char, char> c2c;
    char prev_c1;
    for (int i = 0; i < s.size(); ++i) {
      char c1 = s[i];
      char c2 = t[i];
      if (c2c.count(c1)) {
        if (c2c[c1] != c2) return false;
      } else {
        if (c2c.count(c2) && c2 == c2c[c2]) return false;
        if (i > 0 && c2 == c2c[prev_c1]) return false;
        c2c[c1] = c2;
      }
      prev_c1 = c1;
    }

    return true;
  }
};

int main()
{
  Solution sol;
}
