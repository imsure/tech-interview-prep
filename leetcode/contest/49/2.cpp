#include "../common.hpp"

class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary() {

  }
    
  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    for (auto& word : dict) {
      myDict.insert(word);
    }
  }
    
  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    for (int i = 0; i < word.size(); ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        string word_tmp (word);
        if (c != word[i]) {
          word_tmp[i] = c;
          if (myDict.count(word_tmp)) return true;
        }
      }
    }

    return false;
  }

private:
  unordered_set<string> myDict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
