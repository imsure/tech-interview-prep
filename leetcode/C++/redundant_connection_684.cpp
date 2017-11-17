#include "common.hpp"

// wrong attemp!

class Solution {
private:
  void getTarget(unordered_map<int, unordered_set<int>>& graph,
                 unordered_set<int>& visited, int root, int& target) {
    if (visited.count(root)) {
      target = root; return;
    }
    visited.insert(root);
    for (int node : graph[root]) {
      getTarget(graph, visited, node, target);
      if (target > 0) return;
    }
    return;
  }

  vector<int> getRoots(unordered_map<int, unordered_set<int>>& graph) {
    vector<int> roots; // root node is a node that has no parent
    for (auto& kv : graph) {
      int node = kv.first;
      bool is_root = true;
      for (auto& kv : graph) {
        if (kv.first != node && kv.second.count(node)) {
          is_root = false; break;
        }
      }
      if (is_root) roots.push_back(node);
    }
    return roots;
  }

  void getParent(unordered_map<int, unordered_set<int>>& graph, int target,
                 int root, vector<int>& parent) {
    if (graph[root].count(target)) parent.push_back(root);
    for (int node : graph[root]) {
      getParent(graph, target, node, parent);
    }
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < n; ++i) {
      graph[edges[i][0]].insert(edges[i][1]);
    }

    int target = 0;
    int target_root = 0;
    vector<int> roots = getRoots(graph);
    // for (auto root : roots) cout << "root: " << root << endl;
    for (int root : roots) {
      unordered_set<int> visited;
      getTarget(graph, visited, root, target);
      if (target > 0) {
        target_root = root; break;
      }
    }

    cout << target << endl;
    cout << target_root << endl;

    if (target == 0) { // cycle crosses two connected components
      unordered_set<int> visited;
      for (int root : roots) {
        getTarget(graph, visited, root, target);
        if (target > 0) {
          target_root = root; break;
        }
      }
      cout << target << endl;
      cout << target_root << endl;

      // find two parents of target within the entire graph
      vector<int> nodes;
      // getParentII(graph, target, nodes);

    } else { // cycle is in one connected components
      // get 2 nodes that form a cycle with target
      vector<int> nodes;
      getParent(graph, target, target_root, nodes);
      cout << nodes[0] << ' ' << nodes[1] << endl;

      for (int i = n - 1; i >= 0; --i) {
        if ((edges[i][1] == target && (edges[i][0] == nodes[0] || edges[i][0] == nodes[1]))
            || (edges[i][0] == nodes[0] && edges[i][1] == nodes[1]) ||
            (edges[i][0] == nodes[1] && edges[i][1] == nodes[0])) return edges[i];
      }
    }

    return {};
  }
};


// https://discuss.leetcode.com/topic/110914/a-completely-difference-approach-recursively-remove-leaf-nodes-to-uncover-the-cycle-in-the-graph

class Solution2 {
private:
  void uncoverCycle(unordered_map<int, unordered_set<int>>& graph) {
    int n = graph.size();
    vector<int> remove = {};
    for (auto& kv : graph) {
      int node = kv.first;
      auto& adjlist = kv.second;
      if (adjlist.size() == 1) { // leaf node
        // graph.erase(node);
        remove.push_back(node);
        auto it = adjlist.begin();
        graph[*it].erase(node);
      }
    }

    if (remove.empty()) return;
    else {
      for (int node : remove) graph.erase(node);
      uncoverCycle(graph);
    }
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < n; ++i) { // undirected graph
      graph[edges[i][0]].insert(edges[i][1]);
      graph[edges[i][1]].insert(edges[i][0]);
    }

    // recursively remove leaf nodes to uncover the cycle
    uncoverCycle(graph);
    // for (auto& kv : graph) {
    //   cout << kv.first << ": ";
    //   for (int node : kv.second) cout << node << ' ';
    //   cout << endl;
    // }

    for (int i = n - 1; i >= 0; --i) {
      if (graph.count(edges[i][0]) && graph.count(edges[i][1])) return edges[i];
    }

    return {};
  }
};


// Union-Find without path compression and rank

class UnionFind {
public:
  UnionFind(int N) {
    for (int i = 0; i < N; ++i) parent.push_back(i);
  }

  int find(int i) {
    while (parent[i] != i) i = parent[i];
    return i;
  }

  bool Union(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      parent[rooty] = rootx;
      return true;
    }
    return false;
  }

  void print() {
    for (int i = 1; i < parent.size(); ++i) cout << i << ':' << parent[i] << endl;
    cout << endl;
  }

private:
  vector<int> parent;
};

class Solution3 {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf (n+1);

    for (auto edge : edges) {
      // if two nodes already belong to the same set, that means they are
      // already connected, then this edge would be the redundant connection.
      if (uf.Union(edge[0], edge[1]) == false) return edge;
      // uf.print();
    }

    return {};
  }
};


// Union-Find with path compression and rank

class UnionFind2 {
public:
  UnionFind2(int N) {
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

  void print() {
    for (int i = 1; i < parent.size(); ++i) cout << i << ':' << parent[i] << endl;
    cout << endl;
  }

private:
  vector<int> parent;
  vector<int> rank;
};

class Solution4 {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind2 uf (n+1);

    for (auto edge : edges) {
      // if two nodes already belong to the same set, that means they are
      // already connected, then this edge would be the redundant connection.
      if (uf.Union(edge[0], edge[1]) == false) return edge;
      // uf.print();
    }

    return {};
  }
};


int main()
{
  Solution4 sol;
  vector<vector<int>> edges {{1,2}, {1,3}, {2,3}}; // [2,3]
  // vector<vector<int>> edges {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}}; // [1,4]
  // vector<vector<int>> edges {{1,4}, {3,4}, {1,3}, {1,2}, {4,5}}; // [1,3]
  // vector<vector<int>> edges {{2,7}, {7,8}, {3,6}, {2,5}, {6,8}, {4,8}, {2,8}, {1,8}, {7,10}, {3,9}}; // [2,8]
  // vector<vector<int>> edges {{3,4}, {1,2}, {2,4}, {3,5}, {2,5}}; // [2,5]
  auto res = sol.findRedundantConnection(edges);
  cout << res[0] << ' ' << res[1] << endl;
}
