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


class Solution2 {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> results;
    if (!root) return results;

    deque<TreeNode*> nodes;
    nodes.push_back(root);
    bool l2r = true;

    int sz;
    while (!nodes.empty()) {
      vector<int> values;
      sz = nodes.size();
      while (sz--) {
        TreeNode* node;
        if (l2r) { // for left to right: do pop_front and push_back, left then right
          node = nodes.front();
          nodes.pop_front();
          values.push_back(node->val);
          if (node->left) nodes.push_back(node->left);
          if (node->right) nodes.push_back(node->right);
        } else { // for right to left: do pop_back and push_front, right then left
          node = nodes.back();
          nodes.pop_back();
          values.push_back(node->val);
          if (node->right) nodes.push_front(node->right);
          if (node->left) nodes.push_front(node->left);
        }
      }
      results.push_back(values);
      l2r = l2r ? false : true;
    }

    return results;
  }
};


// two stacks solution

class Solution3 {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> results;
    if (!root) return results;

    stack<TreeNode*> l2r_nodes;
    stack<TreeNode*> r2l_nodes;
    l2r_nodes.push(root);
    bool is_left2right = true;

    while (!l2r_nodes.empty() || !r2l_nodes.empty()) {
      vector<int> values;
      TreeNode* node;
      if (is_left2right) {
        while (!l2r_nodes.empty()) {
          node = l2r_nodes.top();
          l2r_nodes.pop();
          values.push_back(node->val);
          if (node->left) r2l_nodes.push(node->left);
          if (node->right) r2l_nodes.push(node->right);
        }
      } else {
        while (!r2l_nodes.empty()) {
          node = r2l_nodes.top();
          r2l_nodes.pop();
          values.push_back(node->val);
          if (node->right) l2r_nodes.push(node->right);
          if (node->left) l2r_nodes.push(node->left);
        }
      }

      results.push_back(values);
      is_left2right = is_left2right ? false : true;
    }

    return results;
  }
};

int main()
{
  Solution sol;
}
