#include "common.hpp"

// Union Find with path compression and rank

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

// Union Find
// Traverse the matrix and and for each M[i][j] = 1 and i != j, union person i and j.
// Return the # of connected components maintained by UnionFind data structure.

class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();

    UnionFind uf (n);
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        if (M[i][j]) uf.Union(i, j);
      }
    }

    return uf.getCount();
  }
};


// DFS:
// Traverse the matrix (graph), for each person (if not visited), DFS all his friends and mark the
// corresponding cells as 0 to indicate as visited, after that, increment count by 1.
// Skip people that have already been visted (already in some circle that has been identified)

class Solution2 {
private:
  void dfs(vector<vector<int>>& M, int i, int n) {
    M[i][i] = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j && M[i][j]) {
        M[i][j] = 0;
        M[j][i] = 0;
        dfs(M, j, n);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (M[i][i]) {
        ++count;
        dfs(M, i, n);
      }
    }
    return count;
  }
};


int main()
{
  Solution2 sol;
  // vector<vector<int>> M {{1,1,0}, {1,1,0}, {0,0,1}}; // 2
  // vector<vector<int>> M {{1,1,0}, {1,1,1}, {0,1,1}}; // 1
  vector<vector<int>> M {{1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1}}; // 1
  cout << sol.findCircleNum(M) << endl;
}
