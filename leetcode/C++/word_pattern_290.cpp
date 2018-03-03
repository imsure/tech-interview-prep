#include "common.hpp"


class Solution {
public:
  bool wordPattern(string pattern, string str) {
    int i = 0, j = 0;
    unordered_map<char, string> pat2word;
    unordered_map<string, char> word2pat;
    string word;
    int space_count = 0;
    while (i < str.size() && j < pattern.size()) {
      if (str[i] == ' ') {
        char p = pattern[j];
        if (!pat2word.count(p)) pat2word[p] = word;
        else {
          if (pat2word[p] != word) return false;
        }

        if (!word2pat.count(word)) word2pat[word] = p;
        else {
          if (word2pat[word] != p) return false;
        }

        word = "";
        ++j;
        ++space_count;
      } else {
        word.push_back(str[i]);
      }
      ++i;
    }

    if (space_count + 1 != pattern.size()) return false;
    if (pat2word.count(pattern.back()) && pat2word[pattern.back()] != word) return false;
    if (word2pat.count(word) && word2pat[word] != pattern.back()) return false;

    return true;
  }
};

int main()
{
  Solution sol;
  cout << std::boolalpha << sol.wordPattern("abba", "dog cat cat dog") << endl;  // true
  cout << std::boolalpha << sol.wordPattern("abba", "dog cat cat fish") << endl;  // false
  cout << std::boolalpha << sol.wordPattern("aaaa", "dog cat cat fish") << endl;  // false
  cout << std::boolalpha << sol.wordPattern("abba", "dog dog dog dog") << endl;  // false
  cout << std::boolalpha << sol.wordPattern("abbb", "cat dog dog dog") << endl;  // true
}
