#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    string row1 {"qQwWeErRtTyYuUiIoOpP"};
    string row2 {"aAsSdDfFgGhHjJkKlL"};
    string row3 {"zZxXcCvVbBnNmM"};

    map<char, int> key2row {};
    for (const char c : row1) {
      key2row[c] = 1;
    }

    for (const char c : row2) {
      key2row[c] = 2;
    }

    for (const char c : row3) {
      key2row[c] = 3;
    }

    vector<string> res = {};
    bool selected;
    for (const auto& word : words) {
      selected = true;
      for (int i = 0; i < word.size() - 1; ++i) {
        if (key2row[word[i]] != key2row[word[i+1]]) {
          selected = false;
          break;
        }
      }
      if (selected) {
        res.push_back(word);
      }
    }

    return res;
  }
};

int main()
{
  vector<string> words {"Hello", "Alaska", "Dad", "Peace"};
  Solution sol;
  vector<string> res = sol.findWords(words);
  for (const auto& word : res) {
    cout << word << endl;
  }
}
