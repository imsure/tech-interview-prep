#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time:
// space:

class Solution {
private:
  void zigzagLevelOrder(vector<vector<int>>& results,
                        vector<TreeNode*>* nodes, bool leftToRight) {
    if (nodes->size() == 0) return;

    vector<int> values;
    for (int i = 0; i < nodes->size(); ++i) {
      values.push_back(nodes->at(i)->val);
    }
    results.push_back(values);

    vector<TreeNode*> next_level_nodes;
    if (leftToRight) {
      for (int i = nodes->size() - 1; i >= 0; --i) {
        if (nodes->at(i)->right) next_level_nodes.push_back(nodes->at(i)->right);
        if (nodes->at(i)->left) next_level_nodes.push_back(nodes->at(i)->left);
      }
      zigzagLevelOrder(results, &next_level_nodes, false);
    } else {
      for (int i = nodes->size() - 1; i >= 0; --i) {
        if (nodes->at(i)->left) next_level_nodes.push_back(nodes->at(i)->left);
        if (nodes->at(i)->right) next_level_nodes.push_back(nodes->at(i)->right);
      }
      zigzagLevelOrder(results, &next_level_nodes, true);
    }
  }

public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> results;
    if (!root) return results;

    results.push_back(vector<int>{root->val});

    vector<TreeNode*> nodes;
    if (root->right) nodes.push_back(root->right);
    if (root->left) nodes.push_back(root->left);

    zigzagLevelOrder(results, &nodes, false);

    return results;
  }
};

int main()
{
  Solution sol;
}
