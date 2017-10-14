#include "common.hpp"

// brute force: for each substr, check if it contains at most 2 distinct chars
// time: o(n^3) -> TLE

class Solution {
private:
  bool atMostTwoDistinctChars(string s) {
    unordered_set<char> set;
    for (auto c : s) set.insert(c);
    return set.size() <= 2;
  }

public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int max_len = 0;
    for (int front = 0; front < s.size(); ++front) {
      for (int back = s.size() - 1; back >= front; --back) {
        if (atMostTwoDistinctChars(s.substr(front, back-front+1))) {
          max_len = max(max_len, back-front+1);
          break;
        }
      }
    }

    return max_len;
  }
};


// Sliding window approach:
// starting with i = 0 and j = 0, we incrementally discover the window
// [i, j) that contains at most 2 disticnt chars by inserting elements
// in [i, j) into a set. As long as the size of the set is less than 3,
// we keep expanding the window until the size is greater than 2, then
// we stop expanding the window and look back to find the start of the next
// window

class Solution2 {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_set<char> set;
    int i, j, max_len = 0;
    for (i = 0, j = 0; j < s.size(); ++j) {
      if (set.size() < 2) { // insert directly
        set.insert(s[j]);
      } else {
        if (!set.count(s[j])) {
          // stop expanding the current window and shrink the window properly by locating a new place for i
          // element at j is different with two elements in [i,j), so we let i = j-1 and move backwards
          // until s[i] != s[j-1]
          i = j - 1;
          while (s[i] == s[j-1]) --i;
          set.erase(s[i]);
          ++i;
          set.insert(s[j]);
        }
      }

      max_len = max(max_len, j - i + 1);
    }

    return max_len;
  }
};


int main()
{
  Solution2 sol;
  cout << sol.lengthOfLongestSubstringTwoDistinct("") << endl;
  cout << sol.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
  cout << sol.lengthOfLongestSubstringTwoDistinct("aaaa") << endl;
  cout << sol.lengthOfLongestSubstringTwoDistinct("aaaabbbccccc") << endl;
  cout << sol.lengthOfLongestSubstringTwoDistinct("BabBbBbBbbABBABBbAabbbABBaBbBabaabBbbBAAaaAbbAABaAbBBaAaaaaBABbaBbAAbBBbbABBaaBBbab") << endl;
  cout << sol.lengthOfLongestSubstringTwoDistinct("abcabcabc") << endl;
}
