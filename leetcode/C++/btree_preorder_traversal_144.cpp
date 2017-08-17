#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Note: Recursive solution is trivial, could you do it iteratively?
// Like the solution for in-order traversal, the only difference is that
// we print a node's value before pushing it to the stack.

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> values;
    stack<TreeNode*> nodes;
    TreeNode* cur_node = root;

    while (!nodes.empty() || cur_node) {
      if (cur_node) {
        values.push_back(cur_node->val);
        nodes.push(cur_node);
        cur_node = cur_node->left;
      } else {
        TreeNode* pre_node = nodes.top();
        nodes.pop();
        cur_node = pre_node->right;
      }
    }

    return values;
  }
};

int main()
{
  Solution sol;
}
