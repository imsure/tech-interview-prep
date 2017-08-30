#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeWithCount {
  int val;
  int count;
  TreeNodeWithCount *left;
  TreeNodeWithCount *right;
  TreeNodeWithCount(int x) : val(x), count(1), left(NULL), right(NULL) {}
};

TreeNodeWithCount* buildTreeWithCount(TreeNode* root)
{
  if (!root) return nullptr;

  TreeNodeWithCount* _root = new TreeNodeWithCount(root->val);
  _root->left = buildTreeWithCount(root->left);
  _root->right = buildTreeWithCount(root->right);
  if (_root->left) _root->count += _root->left->count;
  if (_root->right) _root->count += _root->right->count;
  return _root;
}

class Solution {
private:
  bool _isValidBST(TreeNodeWithCount* root, TreeNodeWithCount* min_node, TreeNodeWithCount* max_node) {
    if (!root) return true;

    if ((min_node && root->val <= min_node->val) ||
        (max_node && root->val >= max_node->val)) {
      return false;
    }

    return _isValidBST(root->left, min_node, root) && _isValidBST(root->right, root, max_node);
  }

  bool isValidBST(TreeNodeWithCount* root) {
    return _isValidBST(root, nullptr, nullptr);
  }

  int largestBSTSubtree(TreeNodeWithCount* root) {
    if (!root) return 0;
    if (isValidBST(root)) return root->count;
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
  }

public:
  int largestBSTSubtree(TreeNode* root) {
    TreeNodeWithCount* _root = buildTreeWithCount(root);
    return largestBSTSubtree(_root);
  }
};

int main()
{
  Solution sol;
}
