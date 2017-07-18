#include "common.hpp"

// idea: scan the given string s char by char, reverse each work seperately.

// time: O(n), linear to input size, assume reverse a single word takes constant time
// space: O(1), not counting the space taken by the returned string
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

// scan the input char by char, use a stack to store the chars
// until we see a whitespace, then pop out the chars on stack until
// it's empty.

// time: O(n)
// space: O(1), assume a single word takes constant space

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


// credit: https://discuss.leetcode.com/topic/85754/c-solution

// in-place reversing using std::reverse

class Solution3 {
public:
  string reverseWords(string s) {
    int len = s.size();
    int begin_of_word = 0;
    for (int i = 0; i <= len; ++i) {
      if (i == len || s[i] == ' ') {
        std::reverse(&s[begin_of_word], &s[i]);
        begin_of_word = i + 1;
      }
    }

    return s;
  }
};

int main()
{
  string s {"Let's take LeetCode contest"};
  Solution sol;
  cout << sol.reverseWords(s) << endl;

  Solution2 sol2;
  cout << sol2.reverseWords(s) << endl;

  Solution3 sol3;
  cout << sol3.reverseWords(s) << endl;
}
