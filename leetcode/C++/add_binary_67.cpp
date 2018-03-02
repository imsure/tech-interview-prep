#include "common.hpp"


class Solution {
public:
  string addBinary(string a, string b) {
    if (a.empty()) return b;
    if (b.empty()) return a;

    stack<char> tmp;
    int pa = a.size() - 1;
    int pb = b.size() - 1;
    char carry = '0';
    while (pa >= 0 && pb >= 0) {
      char sum = a[pa--] - '0' + b[pb--] - '0' + carry - '0';
      if (sum == 2) {
        tmp.push('0');
        carry = '1';
      } else if (sum == 3) {
        tmp.push('1');
        carry = '1';
      } else {
        tmp.push(sum + '0');
        carry = '0';
      }
    }

    while (pa >= 0) {
      char sum = a[pa--] - '0' + carry - '0';
      if (sum == 2) {
        tmp.push('0');
        carry = '1';
      } else {
        tmp.push(sum + '0');
        carry = '0';
      }
    }
    while (pb >= 0) {
      char sum = b[pb--] - '0' + carry - '0';
      if (sum == 2) {
        tmp.push('0');
        carry = '1';
      } else {
        tmp.push(sum + '0');
        carry = '0';
      }
    }

    if (carry > '0') tmp.push(carry);

    string ans;
    while (!tmp.empty()) {
      ans.push_back(tmp.top());
      tmp.pop();
    }

    return ans;
  }
};


class Solution2 {
public:
  string addBinary(string a, string b) {
    if (a.empty()) return b;
    if (b.empty()) return a;

    string ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int c = 0;
    for ( ; i >= 0 || j >= 0 || c; --i, --j) {
      int op1 = 0, op2 = 0;
      if (i >= 0) op1 = a[i] - '0';
      if (j >= 0) op2 = b[j] - '0';
      int sum = op1 + op2 + c;
      if (sum == 3) {
        ans = '1' + ans;
        c = 1;
      } else if (sum == 2) {
        ans = '0' + ans;
        c = 1;
      } else {
        ans = (char)(sum + '0') + ans;
        c = 0;
      }
    }

    return ans;
  }
};


int main()
{
  Solution2 sol;
  cout << sol.addBinary("11", "1") << endl;
  cout << sol.addBinary("1", "111") << endl;
}
