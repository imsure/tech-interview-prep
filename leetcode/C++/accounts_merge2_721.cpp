#include "common.hpp"

// Build an undirected graph that connects each pair of emails within an account, then
// the problem reduced to finding all connected components in a graph.

class Solution3 {
private:
  // returns a list of 1st degree vertexes to which emails in 'account' belongs
  unordered_set<string> searchGraph(unordered_map<string, unordered_set<string>>& graph, vector<string>& account) {
    unordered_set<string> res;
    for (int i = 1; i < account.size(); ++i) {
      if (graph.count(account[i])) { // email i equals to some 1st degree name, move on with next email
        res.insert(account[i]);
        continue;
      }
      // email does not equal to any 1st degree email, look into 2nd degree emails
      for (auto& kv : graph) {
        if (kv.second.count(account[i])) {
          res.insert(kv.first); // get 1st degree node and break
          break;
        }
      }
    }
    return res;
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans;
    unordered_map<string, unordered_set<string>> graph; // a set of 1st degree vertexes
    unordered_map<string, string> e2n;
    for (auto& a : accounts) {
      auto res = searchGraph(graph, a);
      if (res.empty()) { // add a new 1st degree vertex along with all its 2nd degree neighbors
        if (a.size() > 1)
          e2n[a[1]] = a[0]; // only store name for 1st degree email
          graph.insert(make_pair(a[1], unordered_set<string>{}));
          for (int i = 2; i < a.size(); ++i) {
            graph[a[1]].insert(a[i]);
        }
      } else { // merge 1st degree vertex in 'res' then add current account into it
        auto it = res.begin();
        string key = *it;
        ++it;
        for (; it != res.end(); ++it) {
          string k = *it;
          graph[key].insert(k);
          for (auto email : graph[k]) {
            graph[key].insert(email);
          }
          graph.erase(k);
        }

        for (int i = 1; i < a.size(); ++i) graph[key].insert(a[i]);
      }
    }

    // for (auto& kv : graph) {
    //   cout << e2n[kv.first] << ", " << kv.first;
    //   for (auto& email : kv.second) cout << ", " << email;
    //   cout << endl;
    // }

    for (auto& kv : graph) {
      vector<string> account;
      account.push_back(e2n[kv.first]); // name
      if (!kv.second.count(kv.first)) account.push_back(kv.first); // 1st degree email could also be in 2nd degree email list
      for (auto& email : kv.second) account.push_back(email);
      sort(account.begin(), account.end());
      ans.push_back(account);
    }

    return ans;
  }
};


class Solution4 {
private:
  int findSame(vector<int>& same_table, int start_id) {
    while (same_table[start_id] >= 0) start_id = same_table[start_id];
    return start_id;
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans;
    int n = accounts.size();
    unordered_map<string, int> email2id; // maps email to account id
    vector<int> same_table (n, -1); // smme_table[i] = j means that account i and j is the same account

    // fill the same table
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < accounts[i].size(); ++j) {
        string& email = accounts[i][j];
        if (!email2id.count(email)) email2id[email] = i;
        else { // look up which account also contains this email
          int k = findSame(same_table, email2id[email]);
          if (k != i) same_table[k] = i; // note: k should be less than i
        }
      }
    }

    // construct answer
    for (int i = 0; i < n; ++i) {
      if (same_table[i] < 0) {
        sort(accounts[i].begin() + 1, accounts[i].end());
        auto it = std::unique(accounts[i].begin(), accounts[i].end());
        accounts[i].resize(std::distance(accounts[i].begin(), it));
        ans.push_back(accounts[i]);
      } else {
        int k = findSame(same_table, i);
        for (int j = 1; j < accounts[i].size(); ++j) {
          accounts[k].push_back(accounts[i][j]);
        }
      }
    }

    return ans;
  }
};


// Union Find

class UnionFind {
public:
  UnionFind(int N) {
    for (int i = 0; i < N; ++i) {
      parent.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  bool Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      return true;
    }
    return false;
  }

  void getSets(unordered_map<int, vector<int>>& sets) {
    for (int i = 1; i < parent.size(); ++i) {
      int root = find(i);
      sets[root].push_back(i);
    }
  }

  void print() {
    for (int i = 1; i < parent.size(); ++i) cout << i << ':' << parent[i] << endl;
    cout << endl;
  }

private:
  vector<int> parent;
  vector<int> rank;
};

class Solution5 {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans;
    int n = accounts.size();
    UnionFind uf (n + 1);
    unordered_map<string, int> email2id;
    unordered_map<int, string> id2name;

    for (int i = 0; i < accounts.size(); ++i) {
      int id = i + 1;
      id2name[id] = accounts[i][0];
      for (int j = 1; j < accounts[i].size(); ++j) {
        string& email = accounts[i][j];
        if (email2id.count(email)) uf.Union(id, email2id[email]); // union two accounts if they share a same email
        else email2id[email] = id;
      }
    }

    // uf.print();
    unordered_map<int, vector<int>> sets;
    uf.getSets(sets);
    for (auto& s : sets) {
      vector<string> tmp;
      tmp.push_back(id2name[s.first]);
      set<string> tmpset;
      for (int i : s.second) {
        for (int j = 1; j < accounts[i-1].size(); ++j) tmpset.insert(accounts[i-1][j]);
      }
      for (auto& email : tmpset) tmp.push_back(email);
      ans.push_back(tmp);
    }

    return ans;
  }
};


int main()
{
  Solution5 sol;
  vector<vector<string>> accounts {{"John","johnsmith@mail.com","john_newyork@mail.com"},
      {"John","johnsmith@mail.com","john00@mail.com"}, {"Mary","mary@mail.com"},
                                                          {"John","johnnybravo@mail.com"}};
  // vector<vector<string>> accounts {{"John","johnsmith@mail.com","john_newyork@mail.com"},
  //     {"Mary","mary@mail.com"}, {"John","johnnybravo@mail.com"}};

  auto ans = sol.accountsMerge(accounts);
  for (auto a : ans) {
    for (string s : a) {
      cout << s << ',';
    }
    cout << endl;
  }
}
