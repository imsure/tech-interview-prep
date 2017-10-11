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

int main()
{
  Solution sol;
  cout << sol.isNumber("   ") << endl;
  cout << sol.isNumber(" 3.14 ") << endl;
  cout << sol.isNumber(" 3.14e100 ") << endl;
  cout << sol.isNumber(" 3.14e-5 ") << endl;
  cout << sol.isNumber(" 3.14e-5.6 ") << endl;
  cout << sol.isNumber(" 3.14e- ") << endl;
  cout << sol.isNumber(" 314e+. ") << endl;
  cout << sol.isNumber(" 314e+8") << endl;
  cout << sol.isNumber(" 314e +8") << endl;
  cout << sol.isNumber(".314e+8") << endl;
  cout << sol.isNumber("-.314e+8") << endl;
  cout << sol.isNumber("e+8") << endl;
}
