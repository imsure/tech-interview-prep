#include "common.hpp"


class Solution {
public:
  bool checkRecord(string s) {
    int absent_count = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A') {
        absent_count++;
        if (absent_count > 1) return false;
      }
      if (s[i] == 'L' && i+1 < n && i+2 < n && s[i+1] == 'L' && s[i+2] == 'L') {
        return false;
      }
    }

    return true;
  }
};


int main()
{
  Solution sol;
  cout << std::boolalpha << sol.checkRecord("PPALLL") << endl;
  cout << std::boolalpha << sol.checkRecord("PPALLP") << endl;
}
