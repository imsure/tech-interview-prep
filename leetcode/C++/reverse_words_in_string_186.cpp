#include "common.hpp"

// reverse the entire string first, then reverse
// each word one by one.

class Solution {
public:
  void reverseStr(string& s, int i, int j) {
    while (i < j) {
      swap(s[i++], s[j--]);
    }
  }

  void reverseWords(string& s) {
    int len = s.size();
    reverseStr(s, 0, len - 1);

    int word_start = 0, word_end = 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] != ' ') ++word_end;
      else {
        reverseStr(s, word_start, word_end - 1);
        word_start = word_end = i + 1;
      }
    }
    reverseStr(s, word_start, len - 1);
  }
};

// using std::reverse and two pointers
// note: using std::reverse is less efficient than the above solution.

class Solution2 {
public:
  void reverseWords(string& s) {
    std::reverse(s.begin(), s.end());

    int i, j, len = s.size();
    for (i = 0; i < len; i = j + 1) {
      j = i + 1;
      while (j < len && s[j] != ' ') ++j;
      std::reverse(s.begin() + i, s.begin() + j);
    }
  }
};


int main()
{
  string s {"the sky is blue"};
  Solution2 sol;
  sol.reverseWords(s);
  cout << s << endl;
}
