#include "../common.hpp"

class Solution {
public:
  bool checkValidString(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == '(' || c == '*') stk.push(c);
      else {
        if (stk.empty() || stk.top() == ')') return false;
        if (stk.top() == '(') stk.pop();
        else { // '*'
          stk.pop();
          if (stk.empty()) continue;
          if (stk.top() == '(') {
            stk.pop();
            stk.push('*');
          }
        }
      }
    }

    while (!stk.empty()) {
      if (stk.top() == '(') {
        stk.pop();
        return false;
      } else {
        stk.pop();
        if (!stk.empty() && stk.top() == '(') stk.pop();
      }
    }

    return true;
  }
};

int main()
{
  Solution sol;
  cout << sol.checkValidString("(*)") << endl;
  cout << sol.checkValidString("(*))") << endl;
  cout << sol.checkValidString("(*)))") << endl;
  cout << sol.checkValidString("(*))*)") << endl;

  cout << sol.checkValidString("(()*)(()((())()))(*)((((())*())))()(((()((()(*()))") << endl;
}
