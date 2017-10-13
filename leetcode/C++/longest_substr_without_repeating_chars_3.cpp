#include "common.hpp"

// brute force: for each substr, check if all chars in it are unique
// time: o(n^3) -> TLE

class Solution {
private:
  bool allUnique(string s) {
    unordered_set<char> set;
    for (auto c : s) set.insert(c);
    return set.size() == s.size();
  }

public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    for (int front = 0; front < s.size(); ++front) {
      for (int back = s.size() - 1; back >= front; --back) {
        if (allUnique(s.substr(front, back-front+1))) {
          max_len = max(max_len, back-front+1);
          break;
        }
      }
    }

    return max_len;
  }
};

class Solution2 {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int start = 0, end, max_len = 0;
    for (end = 0; end < s.size(); ++end) {
      if (!set.count(s[end])) {
        set.insert(s[end]); // remember chars that are in the current substr (without repeating ones)
        max_len = max(max_len, end - start + 1);
      } else { // a repeating char is found
        while (start < end) { // move start to point to the char that is right next to the repeated one
          if (s[start++] == s[end]) {
            break;
          } else {
            // erase all the chars before the repeated one so that they can be added into the set again
            set.erase(s[start-1]);
          }
        }
      }
    }

    return max_len;
  }
};

int main()
{
  Solution2 sol;
  cout << sol.lengthOfLongestSubstring("") << endl;
  cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << sol.lengthOfLongestSubstring("bbb") << endl;
  cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
  cout << sol.lengthOfLongestSubstring("abcccdef") << endl;
  cout << sol.lengthOfLongestSubstring("cabcdef") << endl;
  cout << sol.lengthOfLongestSubstring("abcde") << endl;
  cout << sol.lengthOfLongestSubstring("axropfaujpkfgeqohbtvqpzekndgikpkjhyzmbvxqfdyjtnsvinnznujczrmlhwvqxweyr") << endl;
}
