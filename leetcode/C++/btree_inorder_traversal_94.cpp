#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Note: Recursive solution is trivial, could you do it iteratively?

// corner case: if it is a single node tree, return immediately.
//
//

class Solution {
private:
  bool isLeaf(TreeNode* node) {
    return node->left || node->right ? false : true;
  }

public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    if (!root) return res;

    stack<pair<TreeNode*, int>> nodes;
    nodes.push(std::make_pair(root, 0));

    pair<TreeNode*, int> cur_node;
    while (!nodes.empty()) {

      nodes.top().second += 1;
      cur_node = nodes.top();

      if (isLeaf(cur_node.first)) {
        res.push_back(cur_node.first->val);
        nodes.pop();
        continue;
      }

      if (cur_node.first->left && cur_node.second == 1) { // left subtree not visited
        nodes.push(std::make_pair(cur_node.first->left, 0));
        continue;
      } else if (cur_node.first->left && cur_node.second > 1) { // left subtree visited
        res.push_back(cur_node.first->val);
        nodes.pop();
      } else if (cur_node.first->left == nullptr) {
        res.push_back(cur_node.first->val);
        nodes.pop();
      }

      // deal with right subtree
      if (cur_node.first->right) {
        nodes.push(std::make_pair(cur_node.first->right, 0));
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
}
