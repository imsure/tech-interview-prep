#include "common.hpp"

// Brute force, ACed.
// time: O(M) where M is total length of all words, note that look up time for unordered set
// in C++ is constant in average.
// if using a set, time would be O(MlogN) where N is the # of words

class Solution {
public:
  string longestWord(vector<string>& words) {
    unordered_set<string> set;
    for (auto w : words) set.insert(w);

    string ans = "";
    for (auto w : words) {
      bool found = true;
      for (int i = w.size(); i > 0; --i) {
        if (!set.count(w.substr(0, i))) {
          found = false;
          break;
        }
      }
      if (found) {
        if (w.size() > ans.size()) ans = w;
        else if (w.size() == ans.size() && w < ans) ans = w;
      }
    }

    return ans;
  }
};


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

  /** Returns the longest word in trie that can be built one character at a time by other words */
  string longestWord() {
    string ans = "";
    string word = "";
    dfs(root, word, ans);
    return ans;
  }

private:
  void dfs(TrieNode* node, string& word, string& ans) {
    for (int i = 0; i < 26; ++i) {
      if (node->branches[i]) {
        TrieNode* branch;
        branch = node->branches[i];
        if (branch->isWord) {  // only consider nodes ended with a word
          word.push_back('a' + i);
          if (ans.size() < word.size()) ans = word;
          dfs(branch, word, ans);
          word.pop_back();
        }
      }
    }
  }

  TrieNode* root;
};

class Solution2 {
public:
  string longestWord(vector<string>& words) {
    Trie trie;
    for (auto w : words) trie.insert(w);

    return trie.longestWord();
  }
};

// Overwrite comparison function to store words in a set (ordered), then
// iterate through each word in the set in order until we find one.

struct WordCmp {
  bool operator()(const string& w1, const string& w2) {
    if (w1.size() > w2.size()) return true;
    else if (w1.size() < w2.size()) return false;
    else return w1 < w2;
  }
};

class Solution3 {
public:
  string longestWord(vector<string>& words) {
    set<string, WordCmp> word_set (words.begin(), words.end());
    // set<string> word_set;
    // for (auto w : words) word_set.insert(w);

    for (auto w : word_set) {
      int i = w.size() - 1;
      for (; i > 0; --i) {
        if (word_set.find(w.substr(0, i)) == word_set.end()) break;
      }
      if (i == 0) return w;
    }

    return "";
  }
};


int main()
{
  Solution3 sol;
  // vector<string> words {"w","wo","wor","worl", "world"};
  // vector<string> words {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  vector<string> words {"m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"};
  cout << sol.longestWord(words) << endl;
}
