#include "../common.hpp"

class Solution {
public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) return false;

    unordered_map<string, unordered_set<string>> sim_map;
    unordered_map<string, int> word1_map;
    unordered_map<string, int> word2_map;

    for (auto w : words1) word1_map[w]++;
    for (auto w : words2) word2_map[w]++;

    for (auto p : pairs) {
      sim_map[p.first].insert(p.second);
      sim_map[p.second].insert(p.first);
    }

    for (auto w1 : words1) {
      if (word2_map.count(w1)) {
        continue;
      } else {
        if (sim_map.count(w1)) {
          bool found = false;
          for (auto w : sim_map[w1]) {
            if (word2_map.count(w)) { found = true; break;}
          }
          if (found) continue;
          else return false;
        } else return false;
      }
    }

    for (auto w1 : words2) {
      if (word1_map.count(w1)) {
        continue;
      } else {
        if (sim_map.count(w1)) {
          bool found = false;
          for (auto w : sim_map[w1]) {
            if (word1_map.count(w)) { found = true; break;}
          }
          if (found) continue;
          else return false;
        } else return false;
      }
    }

    return true;
  }
};

int main()
{
}
