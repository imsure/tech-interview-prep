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


// better solution

class Solution2 {
public:
  bool isIsomorphic(string s, string t) {
    vector<char> table1 (256, 0);
    vector<char> table2 (256, 0);

    for (int i = 0; i < s.size(); ++i) {
      if (!table1[s[i]] && !table2[t[i]]) {
        table1[s[i]] = t[i];
        table2[t[i]] = s[i];
      } else {
        if (table1[s[i]] != t[i] || table2[t[i]] != s[i]) return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution sol;
}
