#include "common.hpp"

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    unordered_map<string, int> map;

    for (int i = 0; i + 9 < s.size(); ++i) {
      map[s.substr(i, 10)]++;
    }

    for (auto& kv : map) {
      if (kv.second > 1) ans.push_back(kv.first);
    }

    return ans;
  }
};


int main()
{
  Solution sol;
  vector<string> ans = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  // vector<string> ans = sol.findRepeatedDnaSequences("ACGCCGTTC");
  for (auto s : ans) cout << s << endl;
}
