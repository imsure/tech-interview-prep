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


// set + two pointers

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


// vector + two pointers

class Solution3 {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> table (128, false);
    int start = 0, end, max_len = 0;
    for (end = 0; end < s.size(); ++end) {
      if (!table[s[end]]) {
        table[s[end]] = true; // remember chars that are in the current substr (without repeating ones)
        max_len = max(max_len, end - start + 1);
      } else { // a repeating char is found
        while (start < end) { // move start to point to the char that is right next to the repeated one
          if (s[start++] == s[end]) {
            break;
          } else {
            // erase all the chars before the repeated one so that they can be added into the set again
            table[s[start-1]] = false;
          }
        }
      }
    }

    return max_len;
  }
};


// same idea as above, but with a more clear sliding window thought process.

// for each i, find the max sliding window [i, j) where all the chars in the window
// are unique. Use a hashmap to remember all the chars in the current window,
// once we see a repeated char, move i forward until the repeated one becomes
// unique in the updated window.

class Solution4 {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> table (128, false);
    int i = 0, j = 0, n = s.size();
    int max_len = 0;
    while (i < n && j < n) {
      if (!table[s[j]]) {
        table[s[j]] = true;
        // expand the window starting at i
        ++j; max_len = max(max_len, j - i);
      } else {
        // max window has been found at i, move i to the next postition
        table[s[i++]] = false;
      }
    }

    return max_len;
  }
};


// optimized to avoid forwarding i one by one by storing indexes for
// each char in the window so that we can advance i with only one step.

class Solution5 {
public:
  int lengthOfLongestSubstring(string s) {
  }
};


int main()
{
  Solution4 sol;
  cout << sol.lengthOfLongestSubstring("") << endl;
  cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << sol.lengthOfLongestSubstring("bbb") << endl;
  cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
  cout << sol.lengthOfLongestSubstring("abcccdef") << endl;
  cout << sol.lengthOfLongestSubstring("cabcdef") << endl;
  cout << sol.lengthOfLongestSubstring("abcde") << endl;
  cout << sol.lengthOfLongestSubstring("axropfaujpkfgeqohbtvqpzekndgikpkjhyzmbvxqfdyjtnsvinnznujczrmlhwvqxweyr") << endl;
  cout << sol.lengthOfLongestSubstring("axropfaujpkfgeqohbtvqpzekndgikpkjhyzmbvxqfdyjtnsvinnznujczrmlhwvqxweyr&*#)(%&)$(*&%)$&afdjafjapoifjaadfkjakl;dfja;ldddddffffff4444444iiiiiiioooooooo444444444&()&*()&)(*&)(&JJL:ll;jaf;djaf:LKKKLOKLKFPOIDJFOPDSIJFFOJSDPF)fjafkjafdja;fkja;ldfkja;ifjapgijapgoiuapgjapgipagQWERTYUIOPLKJHGFDSAZXCVBNM") << endl;
}
