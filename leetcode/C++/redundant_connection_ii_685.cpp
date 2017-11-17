#include "common.hpp"

// Step 1: find out if there exists a node having two parents, call it 'target'.
// Step 2: if 'target' exists and one of its 'parent' forms a cycle with 'target', e.g.,
//         in graph [4,2],[1,5],[5,2],[5,3],[2,4], 4 <---> 2, then return [4,2]
// Step 3: if the step 2 is not true, then treat the graph as an undirected graph
//         and uncover the cycle in the graph (there must exist a cycle for the graph to be invalid).
//   - if 'target' exists, then return the last edge in the graph where child is 'target' and parent is in the uncovered cycle
//   - if 'target' does not exist, then the problem is the same as problem 684.

class Solution {
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

  void findRedundantConnection(vector<vector<int>>& edges, unordered_map<int, unordered_set<int>>& graph) {
    int n = edges.size();
    for (int i = 0; i < n; ++i) { // undirected graph
      graph[edges[i][0]].insert(edges[i][1]);
      graph[edges[i][1]].insert(edges[i][0]);
    }

    // recursively remove leaf nodes to uncover the cycle
    uncoverCycle(graph);
  }

public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    unordered_map<int, unordered_set<int>> child2parent;
    int n = edges.size();
    int target_child = 0;
    for (int i = 0; i < n; ++i) {
      child2parent[edges[i][1]].insert(edges[i][0]);
      if (child2parent[edges[i][1]].size() > 1) {
        target_child = edges[i][1];
        // break;
      }
    }
    // cout << "target child: " << target_child << endl;

    // special case: detect if there is a 2-node cycle: target_child <---> parent
    for (int parent : child2parent[target_child]) {
      if (child2parent[parent].count(target_child)) return {parent, target_child};
    }

    unordered_map<int, unordered_set<int>> graph;
    findRedundantConnection(edges, graph);

    if (target_child == 0) {
      for (int i = n - 1; i >= 0; --i) {
        if (graph.count(edges[i][0]) && graph.count(edges[i][1])) return edges[i];
      }
    } else {
      for (int i = n - 1; i >= 0; --i) {
        if (edges[i][1] == target_child && graph.count(edges[i][0])) return edges[i];
      }
    }

    return {};
  }
};


// Union Find approach.
// credit: https://discuss.leetcode.com/topic/105108/c-java-union-find-with-explanation-o-n

class Solution2 {
private:
  int root(vector<int>& parent, int u) {
    if (parent[u] != u) parent[u] = root(parent, parent[u]);
    return parent[u];
  }

public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent (n+1, 0);
    vector<int> candA, candB; // two possible edges to be removed if there is a node with 2 parents

    // see if there is a node with 2 parents?
    for (auto& edge : edges) {
      if (parent[edge[1]] == 0) parent[edge[1]] = edge[0];
      else { // exists
        candA = {parent[edge[1]], edge[1]};
        candB = edge;
        edge[1] = 0; // mark this edge as invalid
      }
    }

    // after the above step we are guaranteed to have a graph where each node has only 1 parent

    // Union Find
    for (int i = 1; i < n+1; ++i) parent[i] = i;
    for (auto& edge : edges) {
      if (edge[1] == 0) continue; // skip the marked edge
      int u = edge[0], v = edge[1], parent_of_u = root(parent, u);
      if (parent_of_u == v) { // cycle detected
        if (candA.empty()) return edge; // there is no node with 2 parents, return the edge that forms the cycle
        return candA; // candA is the edge that invalidate the tree
      } else {
        parent[v] = parent_of_u;
      }
    }

    // if after Union Find, the graph is still valid, then candB is the edge that invalidate the tree
    return candB;
  }
};

int main()
{
  Solution2 sol;
  // vector<vector<int>> edges {{1,2}, {1,3}, {2,3}}; // [2,3]
  // vector<vector<int>> edges {{2,1}, {3,1}, {4,2}, {1,4}}; // [2,1]
  vector<vector<int>> edges {{4,2}, {1,5}, {5,2}, {5,3}, {2,4}}; // [4,2]
  auto res = sol.findRedundantDirectedConnection(edges);
  for (int n : res) cout << n << ' ';
  cout << endl;
}
