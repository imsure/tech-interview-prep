#include "common.hpp"

struct TrieNodeOld {
  vector<TrieNodeOld*> branches {26, nullptr};
  bool isWord = false;
};

class TrieOld {
public:
  /** Initialize your data structure here. */
  TrieOld() {
    root = new TrieNodeOld(); // root corresponds to empty string ""
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNodeOld* node = root;
    for (int i = 0; i < word.size(); ++i) {
      if (node->branches[word[i]-'a'] == nullptr) {
        TrieNodeOld* next_node = new TrieNodeOld();
        if (i == word.size() - 1) next_node->isWord = true;
        node->branches[word[i]-'a'] = next_node;
      }
      node = node->branches[word[i]-'a'];
    }

    if (node && !node->isWord) node->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNodeOld* node = root;
    for (int i = 0; i < word.size(); ++i) {
      if (node->branches[word[i]-'a'] == nullptr) return false;
      node = node->branches[word[i]-'a'];
    }
    if (node && node->isWord) return true;
    else return false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNodeOld* node = root;
    for (int i = 0; i < prefix.size(); ++i) {
      if (node->branches[prefix[i]-'a'] == nullptr) return false;
      node = node->branches[prefix[i]-'a'];
    }
    if (node) return true;
    else return false;
  }

private:
  TrieNodeOld* root;
};


// improved code quality and efficiency

struct TrieNode {
  TrieNode* branches[26];
  bool isWord;

  TrieNode (bool isword = false) : isWord(isword) {
    memset(branches, 0, sizeof(branches));
  }
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (node->branches[c - 'a'] == nullptr) node->branches[c - 'a'] = new TrieNode();
      node = node->branches[c - 'a'];
    }
    node->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (node->branches[c - 'a'] == nullptr) return false;
      node = node->branches[c - 'a'];
    }
    return node->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      if (node->branches[c - 'a'] == nullptr) return false;
      node = node->branches[c - 'a'];
    }
    return true;
  }

private:
  TrieNode* root;
};

int main()
{
  Trie trie;
  trie.insert("hello");
  cout << trie.search("hell") << endl; // 0
  cout << trie.search("hello") << endl; // 1
  cout << trie.startsWith("hel") << endl; // 1

  trie.insert("abc");
  cout << trie.search("ab") << endl; // 0
  trie.insert("ab");
  cout << trie.search("ab") << endl;// 1
}
