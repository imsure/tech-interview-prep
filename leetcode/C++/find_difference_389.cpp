#include "common.hpp"

// time:
// space:
class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> charmap;
    for (const char c : s) {
      if (charmap.find(c) == charmap.end())
        charmap[c] = 1;
      else
        charmap[c] += 1;
    }

    for (const char c : t) {
      if (charmap.find(c) == charmap.end() || charmap[c] == 0) {
        return c;
      }
      charmap[c] -= 1;
    }

    return 0;
  }
};

int main()
{
  Solution sol;
  string s {"abcd"}, t {"abcde"};
  cout << sol.findTheDifference(s, t) << endl;

  string s1 {"accd"}, t1 {"ccdac"};
  cout << sol.findTheDifference(s1, t1) << endl;
}
