#include "common.hpp"

struct TrieNode {
  vector<TrieNode*> branches {26, nullptr};
  bool isWord = false;
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
  }
};
