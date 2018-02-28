#include "common.hpp"


class Solution {
public:
  string countAndSay(int n) {
    if (n < 1) return "";
    string cur {"1"};
    for (int i = 2; i <= n; ++i) {
      string next;
      char c = cur[0];
      int count = 0;
      int k = 0;
      while (k < cur.size()) {
        if (cur[k] == c) ++count;
        else {
          next.append(to_string(count));
          next.push_back(c);
          c = cur[k];
          count = 1;
        }
        ++k;
      }
      next.append(to_string(count));
      next.push_back(c);

      cur = next;
    }

    return cur;
  }
};


int main()
{
  Solution sol;
  cout << sol.countAndSay(1) << endl;  // 1
  cout << sol.countAndSay(2) << endl;  // 11
  cout << sol.countAndSay(3) << endl;  // 21
  cout << sol.countAndSay(4) << endl;  // 1211
  cout << sol.countAndSay(5) << endl;  // 111221
}
