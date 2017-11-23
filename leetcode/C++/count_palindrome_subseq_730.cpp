#include "common.hpp"

class Solution {
private:
  unordered_set<string>* _findAllPalindromes(string s, int when_to_end) {
    unordered_set<string>* ans_set_ptr = new unordered_set<string>();
    auto& ans_set = *ans_set_ptr;
    // cout << "s: " << s <<endl;
    for (int i = 0; i < s.size(); ++i) {
      ans_set.insert(string(1, s[i])); // each single char is trivially a palindrome
      // scan s backward to find the first char that is the same as s[i]
      int end = s.size() - 1;
      while (end > when_to_end && s[end] != s[i]) --end;
      if (end > when_to_end) { // matching char found
        when_to_end = end;
        ans_set.insert(string(2, s[i])); // palindrome with two repeated chars
        // recursively solve the smaller problem
        if (end - i - 1 > 0) {
          unordered_set<string>* ans_set_inner_ptr = _findAllPalindromes(s.substr(i+1, end-i-1), 0);
          auto& ans_set_inner = *ans_set_inner_ptr;
          for (auto p : ans_set_inner) {
            ans_set.insert(p);
            ans_set.insert(string(1, s[i]) + p + string(1, s[i]));
          }
          delete ans_set_inner_ptr;
        }
      } else { // no char matches s[i]
        // Here there are two cases to deal with:
        // i is the position of the char that is being matched, if no match is found,
        // in case 1 where i == end, since we are going to search the next
        // char at position i+1, we'd want to set when_to_end at i+1 too.
        // e.g., s = "abc"

        // in case 2 where end is greater i, this means end must be pointing at some
        // char that matches some char before position i, in this case, we don't want
        // to advance when_to_end.
        // e.g., s = "abcac"

        if (i == end) when_to_end = end + 1;
        else when_to_end = end;
      }
    }

    return ans_set_ptr;
  }

public:
  int countPalindromicSubsequences(string S) {
    if (!S.size()) return 0;

    int when_to_end = 0;
    unordered_set<string>* ans_set_ptr = _findAllPalindromes(S, when_to_end);
    auto& ans_set = *ans_set_ptr;

    return ans_set.size() % (1000000000 + 7);
  }
};

class Solution2 {
public:
  int countPalindromicSubsequences(string S) {
    int n = S.size();
  }
};

int main()
{
  Solution sol;
}
