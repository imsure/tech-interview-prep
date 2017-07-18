#include "common.hpp"

// time:
// space:
class Solution {
public:
  string reverseString(string s) {
    for (int i = 0; i < s.size()/2; ++i) {
      swap(s[i], s[s.size() - i - 1]);
    }
    return s;
  }
};

// stack solution
class Solution2 {
public:
  string reverseString(string s) {
    stack<char> tmp_stack;
    for (const char c : s) {
      tmp_stack.push(c);
    }
    char rs[s.size()];
    for (int i = 0; i < s.size(); ++i) {
      rs[i] = tmp_stack.top();
      tmp_stack.pop();
    }
    return string (rs);
  }
};

// two pointers solution

class Solution3 {
public:
  string reverseString(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      swap(s[i++], s[j--]);
    }

    return s;
  }
};

int main()
{
  string s1 {"Let's take LeetCode contest"};
  string s2 {"hello world"};
  Solution sol;
  cout << sol.reverseString(s1) << endl;
  cout << sol.reverseString(s2) << endl;

  Solution2 sol2;
  cout << sol2.reverseString(s1) << endl;
  cout << sol2.reverseString(s2) << endl;

  Solution3 sol3;
  cout << sol3.reverseString(s1) << endl;
  cout << sol3.reverseString(s2) << endl;
}
