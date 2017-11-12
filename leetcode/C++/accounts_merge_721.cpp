#include "common.hpp"


// Brute force: group accounts by name
// time??: O(sum(ai * sum(ej*A*logA))), where ai is the size of account i, ej is the size of email j
// associated with ai, A is the # of emails assciated with account i's name.

// passed with runtime of 408ms, best solution yielded 75ms runtime

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // unordered_map<string, vector<unordered_set<string>>> n2es;
    unordered_map<string, vector<set<string>>> n2es; // name : a list of set of emails

    vector<vector<string>> ans;
    for (auto& a : accounts) {
      auto name = a[0]; // use name as key
      int index = -1;
      for (int i = 1; i < a.size(); ++i) { // for each email associated with the name,
        for (int j = 0; j < n2es[name].size(); ++j) {
          // if it is already in one of email sets linked with the name, we've found the set
          // which all the emails of the current account belongs to
          if (n2es[name][j].count(a[i])) { index = j; break; }
        }
        if (index >= 0) break;
      }

      if (index >= 0) { // insert these emails into the set they belong to
        for (int i = 1; i < a.size(); ++i) {
          n2es[name][index].insert(a[i]);
        }
      } else { // otherwise create a new set
        // unordered_set<string> newset;
        set<string> newset; // use ordered set because we need to output emails in order
        for (int i = 1; i < a.size(); ++i) {
          newset.insert(a[i]);
        }
        n2es[name].push_back(newset);
      }
    }

    // turn map into the temporary answer
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

    // if the size of ans equals the size of accounts, we are done, no more merges needed,
    // otherwise if size of ans < size of accounts, we have to recursively merge ans to
    // make sure we're done.

    if (ans.size() < accounts.size())
      return accountsMerge(ans);
    else return ans;
  }
};


// Build an undirected graph that connects each pair of emails within an account, then
// the problem reduced to finding all connected components in a graph.

struct Vertex {
  string name;
  string email;
  bool firstDegree;
  unordered_set<Vertex*> neighbors; // 2nd degree vertexes
  Vertex* parent; // only for 2nd degree vertex

  Vertex(string n, string e, bool f) : name(n), email(e), firstDegree(f) {}

  bool operator==(Vertex& other) {
    return email == other.email;
  }
};

struct VertexHash { // hash on email field
  std::size_t operator() (const Vertex* v) const {
    return std::hash<string>()(v->email);
  }
};

class Solution2 {
private:
  // returns a list of 1st degree vertexes to which emails in 'account' belongs
  unordered_set<Vertex*> searchGraph(unordered_set<Vertex*, VertexHash>& graph, vector<string>& account) {
    unordered_set<Vertex*> res;
    for (int i = 1; i < account.size(); ++i) {
      Vertex* tmp_v = new Vertex("", account[i], false);
      auto it = graph.find(tmp_v);
      if (it != graph.end()) { // email i equals to some 1st degree name, move on with next email
        res.insert(*it);
        continue;
      }
      // email does not equal to any 1st degree email, look into 2nd degree emails
      for (auto v_1st : graph) {
        auto it = v_1st->neighbors.find(tmp_v);
        if (it != v_1st->neighbors.end()) {
          res.insert((*it)->parent); // get 1st degree node and break
          break;
        }
      }
    }
    return res;
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_set<Vertex*, VertexHash> graph; // a set of 1st degree vertexes
    unordered_set<string> zeroEmailAcc;
    for (auto& a : accounts) {
      auto res = searchGraph(graph, a);
      if (res.empty()) { // add a new 1st degree vertex along with all its 2nd degree neighbors
        if (a.size() < 2) zeroEmailAcc.insert(a[0]);
        else {
          Vertex* v_1st = new Vertex(a[0], a[1], true);
          for (int i = 2; i < a.size(); ++i) {
            Vertex* v_2nd = new Vertex("", a[1], false);
            v_1st->neighbors.insert(v_2nd);
          }
          graph.insert(v_1st);
        }
      }
    }
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
