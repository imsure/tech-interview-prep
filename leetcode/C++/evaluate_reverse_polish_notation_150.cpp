#include "common.hpp"

// time:
// space:

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    if (!tokens.size()) return 0;

    stack<int> operands;
    for (auto t : tokens) {
      if (isdigit(t[t.size()-1])) operands.push(stoi(t));
      else {
        int op1 = operands.top(); operands.pop();
        int op2 = operands.top(); operands.pop();
        int res;
        switch (t[0]) {
        case '+': res = op1 + op2; break;
        case '-': res = op2 - op1; break;
        case '*': res = op1 * op2; break;
        case '/': res = op2 / op1; break;
        default: break;
        }
        operands.push(res);
      }
    }

    return operands.top();
};

int main()
{
  Solution sol;
}
