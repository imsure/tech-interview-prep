#include "common.hpp"

// Sliding window approach:
// starting with i = 0 and j = 0, we incrementally discover the window
// [i, j) that contains at most 2 disticnt chars by inserting elements
// in [i, j) into a set. As long as the size of the set is less than 3,
// we keep expanding the window until the size is greater than 2, then
// we stop expanding the window and look back to find the start of the next
// window

// wrong attemp, abandoned

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0) return 0;

    unordered_set<char> set;
    int i, j, max_len = 0;
    for (i = 0, j = 0; j < s.size(); ++j) {
      if (set.size() < k) { // insert directly
        set.insert(s[j]);
      } else {
        if (!set.count(s[j])) {
          // stop expanding the current window and shrink the window properly by locating a new place for i
          // element at j is different with two elements in [i,j), so we let i = j-1 and move backwards
          // until s[i] != s[j-1]
          int n = j - 1;
          int counter = k - 1;
          int prev_i = i;
          i = n;
          set.clear();
          while (counter--) {
            while (s[i] == s[n]) --i;
            set.insert(s[n]);
            n = i;
          }
          ++i;
          // for (int m = prev_i; m < i; ++m) set.erase(s[m]);
          set.insert(s[j]);
        }
      }

      // cout << "j = " << j << ", i = " << i << endl;
      max_len = max(max_len, j - i + 1);
    }

    return max_len;
  }
};


class Solution2 {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0) return 0;

    int max_len = 0;
    unordered_map<char, int> c2freq;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      c2freq[s[j]]++;
      while (c2freq.size() > k) {
        if (--c2freq[s[i++]] == 0) c2freq.erase(s[i-1]);
      }

      max_len = max(max_len, j - i + 1);
    }

    return max_len;
  }
};


int main()
{
  Solution2 sol;
  cout << sol.lengthOfLongestSubstringKDistinct("", 2) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("eceba", 2) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("aaaa", 2) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("aaaabbbccccc", 2) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("BabBbBbBbbABBABBbAabbbABBaBbBabaabBbbBAAaaAbbAABaAbBBaAaaaaBABbaBbAAbBBbbABBaaBBbab", 2) << endl;

  cout << sol.lengthOfLongestSubstringKDistinct("eceba", 3) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("a", 0) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("abcabc", 2) << endl;
  cout << sol.lengthOfLongestSubstringKDistinct("ababffzzeee", 3) << endl;

  cout << sol.lengthOfLongestSubstringKDistinct("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 64) << endl;
}
