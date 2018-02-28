#include "common.hpp"


class Solution {
public:
  int countSegments(string s) {
    int counter = 0;
    bool seen_nonspace_chars = false;
    for (char c : s) {
      if (c == ' ' || c == '\t') {
        seen_nonspace_chars = false;
        continue;
      }
      if (!seen_nonspace_chars) {
        seen_nonspace_chars = true;
        ++counter;
      }
    }

    return counter;
  }
};


int main()
{
  Solution sol;
  cout << sol.countSegments("Hello, my name is John") << endl;
}
