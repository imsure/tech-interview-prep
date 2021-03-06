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


// Map letters in pattern and words in str to the position index so that
// the letter and word at the position are mapped to the same index. We incrementally
// check if previous seen letter and word are mapped to the same value or not. If not,
// the don't match, return false, otherwise update the index.

class Solution2 {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, int> p2i;
    unordered_map<string, int> w2i;
    istringstream ins (str);
    string word;
    int j;
    for (j = 1; ins >> word; ++j) {
      if (j > pattern.size() || p2i[pattern[j-1]] != w2i[word]) return false;
      p2i[pattern[j-1]] = w2i[word] = j;
    }

    if (j <= pattern.size()) return false;

    return true;
  }
};


int main()
{
  Solution2 sol;
  cout << std::boolalpha << sol.wordPattern("abba", "dog cat cat dog") << endl;  // true
  cout << std::boolalpha << sol.wordPattern("abba", "dog cat cat fish") << endl;  // false
  cout << std::boolalpha << sol.wordPattern("aaaa", "dog cat cat fish") << endl;  // false
  cout << std::boolalpha << sol.wordPattern("abba", "dog dog dog dog") << endl;  // false
  cout << std::boolalpha << sol.wordPattern("abbb", "cat dog dog dog") << endl;  // true
}
