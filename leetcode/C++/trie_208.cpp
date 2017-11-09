#include "common.hpp"

struct TrieNode {
  vector<TrieNode*> branches {27, nullptr};
  bool isWord = false;
  string word = "";
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode(); // root represent empty string ""
  }

  TrieNode* getRoot() { return this->root; }

  void print(TrieNode* root) { // dfs
    if (root->isWord) {
      cout << root->word << endl;
      return;
    }
    for (int i = 0; i < 27; ++i) {
      TrieNode* branch = root->branches[i];
      if (branch) print(branch);
    }
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* cur_node = root;
    for (int i = 0; i < word.size(); ++i) {
      if (cur_node->isWord && cur_node->word == word) return;
      int offset = word[i] - 'a';
      if (cur_node->branches[offset] == nullptr) {
        // if (cur_node->isWord && cur_node->word == word) return; // word already exists in the trie

        TrieNode* new_node = new TrieNode();
        new_node->isWord = true;
        new_node->word = word;
        cur_node->branches[offset] = new_node;
        if (cur_node->isWord) { // turn original leaf node into an internal node
          cur_node->isWord = false;
          insert(cur_node->word);
          cur_node->word = "";
           // TrieNode* new_node2 = new TrieNode();
           // new_node2->isWord = true;
           // new_node2->word = cur_node->word;
           // cur_node->isWord = false;

           // if (cur_node->word.size() <= i) cur_node->branches[26] = new_node2;
           // else cur_node->branches[new_node2->word[i] - 'a'] = new_node2;

           // cur_node->word = "";
        }
        break;
      } else {
        cur_node = cur_node->branches[offset]; // move down
        if (i == word.size() - 1) {
          if (cur_node->isWord && cur_node->word != word) {
            TrieNode* new_node = new TrieNode();
            new_node->isWord = true;
            new_node->word = word;
            cur_node->branches[26] = new_node;
            cur_node->isWord = false;

            TrieNode* new_node2 = new TrieNode();
            new_node2->isWord = true;
            new_node2->word = cur_node->word;
            cur_node->word = "";
            cur_node->branches[new_node2->word[i+1] - 'a'] = new_node2;
          } else if (!cur_node->isWord && !cur_node->branches[26]) {
            TrieNode* new_node = new TrieNode();
            new_node->isWord = true;
            new_node->word = word;
            cur_node->branches[26] = new_node;
          }
        }
      }
    }
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode* cur_node = root;
    for (int i = 0; i < word.size(); ++i) {
      if (cur_node->isWord && cur_node->word == word) return true;

      int offset = word[i] - 'a';
      //cout << "char: " << word[i] << endl;
      //cout << cur_node->branches[offset] << endl;
      if (cur_node->branches[offset] == nullptr) return false;
      cur_node = cur_node->branches[offset];

      if (cur_node->isWord && cur_node->word == word) return true;
      else if (i == word.size() - 1 && cur_node->branches[26]) { // corner case
        return true;
      }
    }

    return false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode* cur_node = root;
    for (int i = 0; i < prefix.size(); ++i) {
      if (cur_node->isWord) {
        if (cur_node->word == prefix) return true;
        else if (prefix.size() < cur_node->word.size()) {
          for (int j = 0; j < prefix.size(); ++j) {
            if (prefix[j] != cur_node->word[j]) return false;
          }
          return true;
        } else return false;
      }

      int offset = prefix[i] - 'a';
      if (cur_node->branches[offset] == nullptr) return false;
      cur_node = cur_node->branches[offset];
    }


    return true;
  }

private:
  TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
  Trie trie;
  trie.insert("acid");
  trie.insert("accept");
  trie.insert("avid");
  trie.insert("abandon");
  trie.insert("bet");
  trie.insert("better");
  trie.insert("best");
  trie.insert("leaf");
  trie.insert("let");
  trie.insert("leave");

  trie.print(trie.getRoot());

  // cout << trie.search("accept") << endl;
  // cout << trie.search("ac") << endl;
  // cout << trie.search("bet") << endl;
  // cout << trie.search("betr") << endl;
  // cout << trie.search("better") << endl;
  // cout << trie.search("leaf") << endl;
  // cout << trie.search("leave") << endl;
  // cout << trie.search("let") << endl;

  cout << trie.startsWith("lea") << endl;
  cout << trie.startsWith("lev") << endl;
  cout << trie.startsWith("avid") << endl;
  cout << trie.startsWith("be") << endl;
  cout << trie.startsWith("abandon") << endl;
  cout << trie.startsWith("bea") << endl;
  cout << trie.startsWith("avi") << endl; // true
}
