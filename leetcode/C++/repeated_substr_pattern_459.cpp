#include "common.hpp"


// Brute force:
// for each substr starting from the beginning, check if the entire
// string is made of this substr by repeating it multiple times.

// time: O(n^2)

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



// idea:
// Given S = 'hello' and T = 'lohel', how do you know if
// t is a rotated version of S ? Check if S is a substring of T + T ('lohellohel').
//
// If S is made of some repeated substrings, then S must equal to some rotation of itself.
// Check if S is a substring of (S + S)[1:-1] basically check if S is present in a rotation
// of itself for all values of R where 0 < R < len(S)

class Solution2 {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    string ss = s + s;
    return ss.substr(1, 2 * n - 2).find(s) != string::npos;
  }
};



// check if s equals to some rotation of itself.
// e.g., s = ababab, then s[0:3] == s[2:5]

class Solution3 {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    int k = n / 2;

    for (int len = 1; len <= k; ++len) {
      string subs = s.substr(0, len);
      if (n % len == 0 && s.substr(len) == s.substr(0, n - len)) return true;
    }

    return false;
  }
};


int main()
{
  Solution3 sol;
  cout << std::boolalpha << sol.repeatedSubstringPattern("a") << endl;  // false
  cout << std::boolalpha << sol.repeatedSubstringPattern("abab") << endl;  // true
  cout << std::boolalpha << sol.repeatedSubstringPattern("abc") << endl;  // false
  cout << std::boolalpha << sol.repeatedSubstringPattern("abcabcabcabc") << endl;  // true
  cout << std::boolalpha << sol.repeatedSubstringPattern("aba") << endl;  // false
}
