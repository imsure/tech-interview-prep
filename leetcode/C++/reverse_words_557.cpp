#include "common.hpp"

// time:
// space:
class Solution {
private:
  string reverseWord(string w) {
    for (int i = 0; i < w.size()/2; ++i) {
      swap(w[i], w[w.size() - i - 1]);
    }
    return w;
  }

public:
  string reverseWords(string s) {
    int start_pos = 0;
    int word_len = 0;
    stringstream ss;
    for (const char c : s) {
      if (c != ' ') {
        ++word_len;
      } else {
        string word = s.substr(start_pos, word_len);
        ss << reverseWord(word);
        ss << ' ';

        start_pos += word_len + 1; // update
        word_len = 0; // reset
      }
    }

    // handle the last word, corner case!
    ss << reverseWord(s.substr(start_pos, word_len));

    return ss.str();
  }
};

class Solution2 {
public:
  string reverseWords(string s) {
    stack<char> tmp_stack;
    stringstream ss;
    for (const char c : s) {
      if (c != ' ') {
        tmp_stack.push(c); // push word to stack
      } else { // pop out the current word on stack
        while (!tmp_stack.empty()) {
          ss << tmp_stack.top();
          tmp_stack.pop();
        }
        ss << ' ';
      }
    }

    while (!tmp_stack.empty()) { // one last word
      ss << tmp_stack.top();
      tmp_stack.pop();
    }

    return ss.str();
  }
};

int main()
{
  string s {"Let's take LeetCode contest"};
  Solution sol;
  cout << sol.reverseWords(s) << endl;

  Solution2 sol2;
  cout << sol2.reverseWords(s) << endl;
}
