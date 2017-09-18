#include "../common.hpp"

class Solution {
public:
  bool check(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
      if (s[i++] != s[j--]) return false;
    }

    return true;
  }

  bool validPalindrome(string s) {
    if (check(s)) {
      return true;
    } else {
      for (int i = 0; i < s.size(); ++i) {
        string s1 = s.substr(0, i) + s.substr(i+1);
        if (check(s1)) return true;
      }
    }

    return false;
  }
};

class Solution2 {
public:
  bool check(string s, int& index1, int& index2) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
      if (s[i++] != s[j--]) {
        index1 = i - 1;
        index2 = j + 1;
        return false;
      }
    }

    return true;
  }

  bool validPalindrome(string s) {
    int i1, i2;
    if (check(s, i1, i2)) {
      return true;
    } else {
      string s1 = s.substr(0, i1) + s.substr(i1+1);
      string s2 = s.substr(0, i2) + s.substr(i2+1);
      return check(s1, i1, i2) || check(s2, i1, i2);
    }
  }
};


int main()
{
  Solution sol;
  cout << sol.validPalindrome("aydmda") << endl;
}
