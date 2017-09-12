#include "common.hpp"

// hashmap + two pointers

// Build a hashmap that maps each word to a list of its positions (since
// we are scanning the array left to right, its guaranteed that the list
// would be sorted). Then given two words, get their lists, and use two
// pointers to find out shortest distance.
// Given two sorted arrays A and B, and two pointers i and j pointing to the start.
// if A[i] < B[j], move i to the next, vice versa and update the shortest distance
// along the way.

class WordDistance {
public:
  WordDistance(vector<string> words) {
    int i = 0;
    for (const auto& word : words) {
      word2index[word].push_back(i++);
    }
  }

  int shortest(string word1, string word2) {
    auto a1 = word2index[word1];
    auto a2 = word2index[word2];

    int i = 0, j = 0, min_dist = numeric_limits<int>::max();
    while (i < a1.size() && j < a2.size()) {
      min_dist = min(min_dist, abs(a1[i] - a2[j]));
      if (a1[i] < a2[j]) ++i;
      else ++j;
    }

    return min_dist;
  }

private:
  unordered_map<string, vector<int>> word2index;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

int main()
{
}
