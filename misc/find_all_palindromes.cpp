/**
 * Problem: given a string s, find all palindromes contained
 * within s where each palindrome is a subsequence (not substr) of s.
 *
 * e.g., for s = "abcabc", output would be:
 * a, b, c, aa, bb, cc, aba, aca, bcb, bab, cac, cbc
 */

#include "common.hpp"

class Solution {
private:
  unordered_set<string> _findAllPalindromes(string s, int when_to_end) {
    unordered_set<string> ans_set;

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
          unordered_set<string> ans_set_inner = _findAllPalindromes(s.substr(i+1, end-i-1), 0);
          for (auto p : ans_set_inner) {
            ans_set.insert(p);
            ans_set.insert(string(1, s[i]) + p + string(1, s[i]));
          }
        }
      } else {
        if (i == end) when_to_end = end + 1;
        else when_to_end = end;
      }
    }

    return ans_set;
  }

public:
  vector<string> findAllPalindromes(string s) {
    vector<string> ans;
    if (!s.size()) return ans;

    int when_to_end = 0;
    unordered_set<string> ans_set = _findAllPalindromes(s, when_to_end);
    for (auto p : ans_set) {
      ans.push_back(p);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  // vector<string> ans = sol.findAllPalindromes("abcabc");
  // vector<string> ans = sol.findAllPalindromes("abcac");
  // vector<string> ans = sol.findAllPalindromes("abc");
  // vector<string> ans = sol.findAllPalindromes("abbcca");
  vector<string> ans = sol.findAllPalindromes("abbbba");
  for (auto s : ans) {
    cout << s << endl;
  }
}
