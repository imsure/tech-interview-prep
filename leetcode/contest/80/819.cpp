#include "../common.hpp"


class Solution {
public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> banned_set;
    for (auto s : banned) banned_set.insert(s);

    int max_count = 0;
    unordered_map<string, int> word_count;
    string word, ans;
    for (int i = 0; i < paragraph.size(); ++i) {
      char c = paragraph[i];
      if (isalpha(c)) {
        if (isupper(c)) c = tolower(c);
        word.push_back(c);
      } else if (c == ' ' || c == '\t') {
        if (banned_set.count(word)) {
          word.clear();
          continue;
        }
        word_count[word]++;
        if (word_count[word] > max_count) {
          max_count = word_count[word];
          ans = word;
        }
        word.clear();
      }
    }

    if (word.size() && !banned_set.count(word)) {
      word_count[word]++;
      if (word_count[word] > max_count) {
        max_count = word_count[word];
        ans = word;
      }
    }
    return ans;
  }
};


int main()
{
  Solution sol;
  vector<string> banned {"hit"};
  cout << sol.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned) << endl;
  vector<string> banned2 {};
  cout << sol.mostCommonWord("a.", banned2) << endl;
}
