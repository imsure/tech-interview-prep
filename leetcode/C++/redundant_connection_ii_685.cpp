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


int main()
{
  Solution sol;
   vector<vector<int>> edges {{1,2}, {1,3}, {2,3}}; // [2,3]
  // vector<vector<int>> edges {{2,1}, {3,1}, {4,2}, {1,4}}; // [2,1]
  // vector<vector<int>> edges {{4,2}, {1,5}, {5,2}, {5,3}, {2,4}}; // [4,2]
  auto res = sol.findRedundantDirectedConnection(edges);
  for (int n : res) cout << n << ' ';
  cout << endl;
}
