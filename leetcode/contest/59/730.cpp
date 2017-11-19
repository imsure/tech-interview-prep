/**
 * Problem: given a string s, find all palindromes subsequences in s.
 *
 * Note that a subsequence of a string s is obtained by deleting 0 or more
 * characters (not necessarily to be consecutive) from s.
 *
 * e.g., for s = "abcabc", output would be:
 * a, b, c, aa, bb, cc, aba, aca, bcb, bab, cac, cbc
 */

#include "../common.hpp"

// Approach: for each char 'c' in s from start to end, put 'c' into the answer set and
// scan s backwards to see if there is another 'c' in s, if yes, put 'cc' into the answer
// set and recursively find all palindromes of the substr between two 'c's, augment
// the returned answer by prefixing a 'c' and appending a 'c' for each palindromes in the substr.

// e.g., s = "abca", we find two 'a's at 0 and 3, put "a" and "aa" into answer set,
// then we recursively find all palindromes of "bc" which is "b" and "c", we expend to include "aba" and "aca".

// Note that for each char we don't have to scan from the last char all the way back to the first char,
// we just need to remember the position of the char that matches the previous char and stop right there.
// e.g., s = "abcbac"
//            ^   ^
//            0   4
// we've found two a's at 0 and 4, when we scan for b at 1, we stop as we see a at 4, because we've already
// solved the substr "bcb" in between two a's at 0 and 4, there is not need to do it again.

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

int main()
{
  Solution sol;
  // vector<string> ans = sol.findAllPalindromes("abcabc");
  // cout << sol.countPalindromicSubsequences("abca") << endl;

  // vector<string> ans = sol.findAllPalindromes("abc");
  // vector<string> ans = sol.findAllPalindromes("abbcca");
  // vector<string> ans = sol.findAllPalindromes("abbbba");
  // vector<string> ans = sol.findAllPalindromes("abcad");
  // vector<string> ans = sol.findAllPalindromes("abcaded");
  // vector<string> ans = sol.findAllPalindromes("abccb");
  // vector<string> ans = sol.findAllPalindromes("abcbac");
  // vector<string> ans = sol.findAllPalindromes("ACGATGTAC");
  // cout << sol.countPalindromicSubsequences("bccb") << endl;
  cout << sol.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << endl;
}
