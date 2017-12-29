#include "common.hpp"

// Union-Find with path compression and rank
// For details, you can refer to this article: https://leetcode.com/articles/redundant-connection/

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

// time:
// space:

class Solution {
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    UnionFind uf (n);
    for (auto edge : edges) {
      uf.Union(edge.first, edge.second);
    }
    return uf.getCount();
  }
};

int main()
{
  Solution sol;
  // vector<pair<int, int>> edges {{0,1}, {1,2}, {3,4}};
  vector<pair<int, int>> edges {{0,1}, {1,2}, {3,4}, {2,3}};
  cout << sol.countComponents(5, edges) << endl;
}
