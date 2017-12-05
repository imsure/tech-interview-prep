#include "../C++/common.hpp"

class Solution {
public:
  int monotoneIncreasingDigits(int N) {
    string strN = std::to_string(N);
    int i;
    for (i = 0; i < strN.size() - 1; ++i) {
      if (strN[i] > strN[i+1]) break;
    }

    if (i < strN.size() - 1) {
      for (int j = i + 1; j < strN.size(); ++j) strN[j] = '9';
      strN[i] -= 1;
      for (int j = i; j > 0; --j) {
        if (strN[j] < strN[j-1]) {
          strN[j] = '9';
          strN[j-1] -= 1;
        }
      }
    }

    return std::stoi(strN);
  }
};


int main()
{
  Solution sol;
  cout << sol.monotoneIncreasingDigits(1234) << endl; // 1234
  cout << sol.monotoneIncreasingDigits(10) << endl; // 9
  cout << sol.monotoneIncreasingDigits(332) << endl; // 299
  cout << sol.monotoneIncreasingDigits(101) << endl; // 99
  cout << sol.monotoneIncreasingDigits(120) << endl; // 119
  cout << sol.monotoneIncreasingDigits(1280) << endl; // 1279
  cout << sol.monotoneIncreasingDigits(2180) << endl; // 1999
  cout << sol.monotoneIncreasingDigits(11100) << endl; // 9999
}
