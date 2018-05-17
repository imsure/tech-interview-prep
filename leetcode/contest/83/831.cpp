#include "../common.hpp"


class Solution {
private:
  string mask_email(string S) {
    int n = S.size();
    for (int i = 0; i < n; ++i) S[i] = tolower(S[i]);

    int pos = S.find('@');
    S.replace(1, pos - 2, "*****");
    // for (int i = 1; i < pos - 1; ++i) S[i] = '*';
    return S;
  }

  string mask_phone(string S) {
    vector<char> digits;
    int n = S.size();

    for (int i = 0; i < n; ++i) {
      if (isdigit(S[i])) {
        digits.push_back(S[i]);
      }
    }

    string country_code;
    int num_digits = digits.size();
    if (num_digits > 10) {
      for (int i = 0; i < num_digits - 10; ++i) {
        country_code.push_back(digits[i]);
      }
    }

    string ret;
    if (country_code.size() > 0) {
      ret.push_back('+');
      ret.append(string(country_code.size(), '*'));
      ret.push_back('-');
    }

    ret.append("***-***-");
    for (int i = num_digits - 4; i < num_digits; ++i) {
      ret.push_back(digits[i]);
    }

    return ret;
  }

public:
  string maskPII(string S) {
    if (isalpha(S[0])) return mask_email(S);
    return mask_phone(S);
  }
};


int main()
{
  Solution sol;
  cout << sol.maskPII("LeetCode@LeetCode.com") << endl;
  cout << sol.maskPII("1(234)567-890") << endl;
  cout << sol.maskPII("86-(10)12345678") << endl;
  cout << sol.maskPII("AB@qq.com") << endl;
}
