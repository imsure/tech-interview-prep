#include "common.hpp"

// 1. map word to wordcount for two word list and map each word to its pair in 'pairs'
// 2. iterative each word in words1, decrement its counter in the corresponding map, if counter becomes
//    0, remove the map entry; meanwhile search if this word is also in words2 by first consult to words2 map
//    and if not exist, then consult to pairs map, if not exist, then return false, otherwise decrement the corresponding counter in words2 map
// 3. if at the end, both words1 and word2 map become empty, return true

class Solution {
public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    int len1 = words1.size();
    int len2 = words2.size();
    if (len1 != len2) return false;

    unordered_map<string, int> map1, map2;
    unordered_map<string, vector<string>> pairmap;

    for (auto& word : words1) map1[word]++;
    for (auto& word : words2) map2[word]++;
    for (auto& p : pairs) {
      pairmap[p.first].push_back(p.second);
      pairmap[p.second].push_back(p.first);
    }

    for (auto& word : words1) {
      map1[word]--;
      if (map1[word] == 0) map1.erase(word);

      if (map2.count(word)) {
        map2[word]--;
        if (map2[word] == 0) map2.erase(word);
      } else {
        if (pairmap.count(word)) {
          for (auto& s : pairmap[word]) {
            if (map2.count(s)) {
              map2[s]--;
              if (map2[s] == 0) map2.erase(s);
              break;
            }
          }
        } else {
          return false;
        }
      }
    }

    return map1.empty() && map2.empty();
  }
};


class Solution2 {
public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    int len1 = words1.size();
    int len2 = words2.size();
    if (len1 != len2) return false;

    set<pair<string, string>> pairmap;

    for (auto& p : pairs) {
      pairmap.insert(p);
      pairmap.insert({p.second, p.first});
    }

    for (int i = 0; i < len1; ++i) {
      if (words1[i] == words2[i]) continue;
      if (pairmap.count({words1[i], words2[i]}) ||
          pairmap.count({words2[i], words1[i]})) continue;
      else return false;
    }

    return true;
  }
};


int main()
{
  Solution2 sol;
  vector<string> words1 {"great", "acting", "skills"};
  vector<string> words2 {"fine", "drama", "talent"};
  vector<pair<string, string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}};

  cout << sol.areSentencesSimilar(words1, words2, pairs) << endl;
}
