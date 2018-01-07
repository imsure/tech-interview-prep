#include "common.hpp"

// time:
// space:

class Solution {
public:
  int romanToInt(string s) {
    if (s.size() == 0) return 0;

    unordered_map<char, int> table;
    table.insert({'I', 1});
    table.insert({'V', 5});
    table.insert({'X', 10});
    table.insert({'L', 50});
    table.insert({'C', 100});
    table.insert({'D', 500});
    table.insert({'M', 1000});

    int ans = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
      int val = table[s[i]];
      int next_val = table[s[i+1]];
      if (val >= next_val) ans += val;
      else ans -= val;
    }
    ans += table[s[s.size()-1]];
    return ans;
  }
};

int main()
{
  Solution sol;
  cout << sol.romanToInt("LXXXIX") << endl; // 89
  cout << sol.romanToInt("VIII") << endl; // 8
  cout << sol.romanToInt("XCIX") << endl; // 99
}
