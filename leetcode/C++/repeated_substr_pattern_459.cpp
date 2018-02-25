#include "common.hpp"


class Solution {
private:
  bool matched(string s, string subs) {
    int len_s = s.size();
    int len_subs = subs.size();

    if (len_s % len_subs) return false;
    for (int pos = len_subs; pos < len_s; pos += len_subs) {
      if (s.substr(pos, len_subs) != subs) return false;
    }

    return true;
  }

public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    int k = n / 2;

    for (int len = 1; len <= k; ++len) {
      string subs = s.substr(0, len);
      if (matched(s, subs)) return true;
    }

    return false;
  }
};


int main()
{
  Solution sol;
  cout << std::boolalpha << sol.repeatedSubstringPattern("a") << endl;  // false
  cout << std::boolalpha << sol.repeatedSubstringPattern("abab") << endl;  // true
  cout << std::boolalpha << sol.repeatedSubstringPattern("abc") << endl;  // false
  cout << std::boolalpha << sol.repeatedSubstringPattern("abcabcabcabc") << endl;  // true
  cout << std::boolalpha << sol.repeatedSubstringPattern("aba") << endl;  // false
}
