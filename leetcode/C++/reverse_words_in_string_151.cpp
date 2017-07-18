#include "common.hpp"

// reverse each word from the end to the start of the given string,
// and move all the extra whitespaces backwards along the way. At the
// end of the operation, all the extra whitespaces will be the leading
// whitespaces of the reversed string. Then erase the leading whitespaces
// then reverse the entire string again.

// time: O(n)
// space: O(1), in place reversing

class Solution {
public:
  void reverseWords(string& s) {
    int len = s.size();
    int word_start = len - 1; // point to the start of the word to be reversed
    int word_end = len - 1; // point to the end of the word to be reversed
    int word_len;

    while (word_start >= 0) {
      word_len = 0;
      // skip the trailing whitespaces of the current word
      while (word_start >= 0 && isblank(s[word_start])) --word_start;
      // skip the chars of the current word until a whitespace is seen or the beginning of the string is reached
      while (word_start >= 0 && !isblank(s[word_start])) {
        --word_start;
        ++word_len;
      }

      std::reverse(s.begin() + word_start + 1, s.begin() + word_end + 1);
      --word_start; // skip the single whitespace that seperates two words
      word_end = word_end - word_len - 1; // update
    }

    // remove the leading spaces
    int i;
    for (i = 0; i < len && isblank(s[i]); ++i) ;

    s.erase(s.begin(), s.begin() + i);

    std::reverse(s.begin(), s.end());
  }
};

int main()
{
  string s {"the sky is blue"};
  // string s {"the sky is blue    "};
  // string s {"  the sky is blue    "};
  // string s {"  the  sky is blue    "};
  // string s {"  the  sky   is  blue    "};
  // string s {"      "};
  Solution sol;
  sol.reverseWords(s);
  cout << s << endl;
}
