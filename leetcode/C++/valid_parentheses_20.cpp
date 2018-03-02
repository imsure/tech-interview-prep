#include "common.hpp"


class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> m;
    m['('] = ')';
    m['['] = ']';
    m['{'] = '}';

    stack<char> stk;
    for (char c : s) {
      if (c == '(' || c == '{' || c == '[') stk.push(c);
      else {
        if (stk.empty()) return false;
        if (m[stk.top()] != c) return false;
        stk.pop();
      }
    }

    return stk.empty();
  }
};


int main()
{
  Solution sol;
  cout << std::boolalpha << sol.isValid("([{}])") << endl;
  cout << std::boolalpha << sol.isValid("([{])") << endl;
}
