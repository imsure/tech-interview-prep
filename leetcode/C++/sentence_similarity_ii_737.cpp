#include "common.hpp"

// wrong attemp!

class Solution {
private:
  void addSimilarWords(string& word1, string& word2, set<pair<string, string>>& pairmap) {
    for (auto& p : pairmap) {
      if (p.first == word2) {
        pairmap.insert({word1, p.second});
        pairmap.insert({p.second, word1});
      } else if (p.second == word2) {
        pairmap.insert({word1, p.first});
        pairmap.insert({p.first, word1});
      }
    }
  }

  bool checkSimilarity(string& word1, string& word2, set<pair<string, string>>& pairmap) {
    if (pairmap.count({word1, word2}) ||
        pairmap.count({word2, word1})) return true;

    for (auto& p : pairmap) {
      if (p.first == word2) {
        if (pairmap.count({word1, p.second}) || pairmap.count({p.second, word1})) return true;
      } else if (p.second == word2) {
        if (pairmap.count({word1, p.first}) || pairmap.count({p.first, word1})) return true;
      }
    }

    return false;
  }

public:
  bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    int len1 = words1.size();
    int len2 = words2.size();
    if (len1 != len2) return false;

    set<pair<string, string>> pairmap;

    for (auto& p : pairs) {
      auto& w1 = p.first;
      auto& w2 = p.second;

      // all words similar to w2 are also smilar to w1
      // addSimilarWords(w1, w2, pairmap);
      // all words similar to w1 are also smilar to w2
      // addSimilarWords(w2, w1, pairmap);

      pairmap.insert(p);
      pairmap.insert({w2, w1});
    }

    for (int i = 0; i < len1; ++i) {
      if (words1[i] == words2[i]) continue;
      if (checkSimilarity(words1[i], words2[i], pairmap)) continue;
      else return false;
    }

    return true;
  }
};


class UnionFind {
public:
  UnionFind(int N) {
    count = N;
    for (int i = 0; i < N; ++i) {
      parent.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

// Union Find:
// map each unique word in 'pairs' to an ID which starts from 0 and monotonically increasing,
// then use Union Find data structure to keep similars words in connected components.

class Solution2 {
public:
  bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    int len1 = words1.size();
    int len2 = words2.size();
    if (len1 != len2) return false;

    int id = 0;
    unordered_map<string, int> word2id;
    for (auto& p : pairs) {
      if (!word2id.count(p.first)) word2id[p.first] = id++;
      if (!word2id.count(p.second)) word2id[p.second] = id++;
    }

    UnionFind uf (id);
    for (auto& p : pairs) {
      string& w1 = p.first;
      string& w2 = p.second;
      uf.Union(word2id[w1], word2id[w2]);
    }

    for (int i = 0; i < len1; ++i) {
      string& w1 = words1[i];
      string& w2 = words2[i];
      if (w1 == w2) continue;
      if (word2id.count(w1) && word2id.count(w2) &&
          uf.find(word2id[w1]) == uf.find(word2id[w2])) continue;
      else return false;
    }

    return true;
  }
};


int main()
{
  Solution2 sol;
  vector<string> words1 {"great", "acting", "skills"};
  vector<string> words2 {"good", "drama", "talent"};
  vector<pair<string, string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}, {"good", "fine"}};

  cout << sol.areSentencesSimilarTwo(words1, words2, pairs) << endl;
}
