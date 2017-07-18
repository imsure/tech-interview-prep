#include "common.hpp"

// two pointers solution

class Solution {
public:
  bool isVowel(char c) {
    bool is_lower_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    bool is_upper_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    return (is_lower_vowel || is_upper_vowel);
  }

  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j && !isVowel(s[i])) ++i;
      while (i < j && !isVowel(s[j])) --j;

      if (i < j) {
        std::swap(s[i++], s[j--]);
      }
    }

    return s;
  }
};

int main()
{
  string s {"hello"};
  Solution sol;
  cout << sol.reverseVowels(s) << endl;
}
