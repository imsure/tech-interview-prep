#include "../common.hpp"

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // unordered_map<string, vector<unordered_set<string>>> n2es;
    unordered_map<string, vector<set<string>>> n2es;

    vector<vector<string>> ans;
    for (auto& a : accounts) {
      auto name = a[0];
      int index = -1;
      for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < n2es[name].size(); ++j) {
          if (n2es[name][j].count(a[i])) { index = j; break; }
        }
        if (index >= 0) break;
      }

      if (index >= 0) {
        for (int i = 1; i < a.size(); ++i) {
          n2es[name][index].insert(a[i]);
        }
      } else {
        // unordered_set<string> newset;
        set<string> newset;
        for (int i = 1; i < a.size(); ++i) {
          newset.insert(a[i]);
        }
        n2es[name].push_back(newset);
      }
    }

    for (auto& kv : n2es) {
      for (auto& l : kv.second) {
        vector<string> acc;
        acc.push_back(kv.first);
        for (auto email : l) {
          acc.push_back(email);
        }
        ans.push_back(acc);
      }
    }

    // return ans;
    if (ans.size() < accounts.size())
      return accountsMerge(ans);
    else return ans;
  }
};

int main()
{
  Solution sol;
  vector<vector<string>> accounts {{"John","johnsmith@mail.com","john_newyork@mail.com"},
      {"John","johnsmith@mail.com","john00@mail.com"}, {"Mary","mary@mail.com"},
                                                         {"John","johnnybravo@mail.com"}};
  auto ans = sol.accountsMerge(accounts);
  for (auto a : ans) {
    for (string s : a) {
      cout << s << ',';
    }
    cout << endl;
  }
}
