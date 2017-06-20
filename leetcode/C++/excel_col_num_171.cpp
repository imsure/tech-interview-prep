#include "common.hpp"

// time:
// space:
class Solution {
public:
  int titleToNumber(string s) {
    int col_num = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
      col_num += pow(26, len - 1 - i) * (s[i] - 'A' + 1);
    }

    return col_num;
  }
};

int main()
{
  Solution sol;
  cout << sol.titleToNumber("A") << endl;
  cout << sol.titleToNumber("AB") << endl;
  cout << sol.titleToNumber("CA") << endl;
}
