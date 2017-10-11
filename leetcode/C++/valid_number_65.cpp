#include "common.hpp"

class Solution {
public:
  bool isNumber(string s) {
    if (s.empty()) return false;

    // remove the leading and trailing spaces
    int start = 0, end = s.size() - 1;
    while (start < s.size() && s[start] == ' ') ++start;
    while (end >= 0 && s[end] == ' ') --end;
    s = s.substr(start, end - start + 1);
    if (s.empty()) return false;


    // there must be at least one digit;
    // a valid number must begin with +, -, dot or a digit;
    // +,- signs can appear only at the beginning or follow the 'e';
    // 'e' can only follow a digit or a dot sign;
    // there can be at most one dot sign and one 'e';

    // [+-]?(([0-9]+(.[0-9]*))|(.[0-9]+))(e[+-]?[0-9]+)?

    bool digits_seen = false;
    bool dot_seen = false;
    bool e_seen = false;
    bool digit_after_e = false;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        if (e_seen) digit_after_e = true;
        else digits_seen = true;
      } else if (s[i] == '+' || s[i] == '-') {
        if (i != 0  && s[i-1] != 'e') return false;
      } else if (s[i] == '.') {
        if (dot_seen) return false;
        if (e_seen) return false;
        dot_seen = true;
      } else if (s[i] == 'e') {
        if (e_seen) return false;
        e_seen = true;
      } else {
        return false;
      }
    }

    return e_seen ? digits_seen && digit_after_e : digits_seen;
  }
};


class Solution2 {
public:
  bool isNumber(string s) {
    if (s.empty()) return false;

    int i;
    int n = s.size();
    for (i = 0; i < n && s[i] == ' '; ++i) ; // skip the leading whitespaces

    if (i >= n) return false;
    else if (s[i] == '+' || s[i] == '-') ++i; // skip the + or - sign if any

    if (i >= n) return false;
    else {
      int n_digits = 0, n_dots = 0;
      for (; i < n && ((s[i] <= '9' && s[i] >= '0') || s[i] == '.'); ++i) {
        s[i] == '.' ? ++n_dots : ++n_digits;
      }

      if (n_dots > 1 || n_digits < 1) return false;

      if (i >= n) return true;
      if (s[i] == 'e') {
        ++i;
        if (i >= n) return false;
        else if (s[i] == '+' || s[i] == '-') ++i; // skip the + or - sign if any

        int n_digits = 0;
        for (; i < n && (s[i] <= '9' && s[i] >= '0'); ++i) {
          ++n_digits;
        }
        if (n_digits < 1) return false;
      }
    }

    for (; i < n && s[i] == ' '; ++i) ; // skip the trailing whitespaces
    return i == n;
  }
};

int main()
{
  Solution2 sol;
  cout << sol.isNumber("   ") << endl;        // 0
  cout << sol.isNumber(" 3.14 ") << endl;     // 1
  cout << sol.isNumber(" 3.14e100 ") << endl; // 1
  cout << sol.isNumber(" 3.14e-5 ") << endl;  // 1
  cout << sol.isNumber(" 3.14e-5.6 ") << endl;// 0
  cout << sol.isNumber(" 3.14e- ") << endl;   // 0
  cout << sol.isNumber(" 314e+. ") << endl;   // 0
  cout << sol.isNumber(" 314e+8") << endl;    // 1
  cout << sol.isNumber(" 314e +8") << endl;   // 0
  cout << sol.isNumber(".314e+8") << endl;    // 1
  cout << sol.isNumber("-.314e+8") << endl;   // 1
  cout << sol.isNumber("e+8") << endl;        // 0
}
