#include "common.hpp"

// one pass: use two pointers i and j as indexes where word1 and word2 last seen,
// except when word1 == word2, i is the previous index and j is the current index.

// time: O(n)
// space: O(1)

class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int len = words.size();
    int min_dist = len;
    bool same = (word1 == word2);
    int p1 = -1, p2 = -1;

    for (int i = 0; i < len; ++i) {
      if (same && words[i] == word1) {
        if (p1 == -1 && p2 == -1) p1 = i;
        else if (p1 != -1 && p2 == -1) p2 = i;

        if (p1 != -1 && p2 != -1) {
          min_dist = min(min_dist, abs(p1 - p2));
          p1 = p2;
          p2 = -1;
        }
      } else {
        if (words[i] == word1) p1 = i;
        else if (words[i] == word2) p2 = i;

        if (p1 != -1 && p2 != -1) {
          min_dist = min(min_dist, abs(p1 - p2));
        }
      }
    }

    return min_dist;
  }
};

int main()
{
  Solution sol;
  vector<string> words {"practice", "makes", "perfect", "coding", "makes"};
  cout << sol.shortestDistance(words, "coding", "practice") << endl;
  cout << sol.shortestDistance(words, "coding", "makes") << endl;
}
