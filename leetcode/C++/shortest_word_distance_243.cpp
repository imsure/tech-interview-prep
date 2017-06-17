#include "common.hpp"

// time:
// space:
class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int len = words.size();
    int index_word1 = -1, index_word2 = -1;

    int distance = len;
    for (int i = 0; i < len; ++i) {
      if (word1 == words[i]) {
        index_word1 = i;
      } else if (word2 == words[i]) {
        index_word2 = i;
      }

      if (index_word1 != -1 && index_word2 != -1) {
        distance = min(distance, abs(index_word1 - index_word2));
      }
    }

    return distance;
  }
};

int main()
{
  Solution sol;
  vector<string> words {"practice", "makes", "perfect", "coding", "makes"};
  cout << sol.shortestDistance(words, "coding", "practice") << endl;
  cout << sol.shortestDistance(words, "coding", "makes") << endl;
}
