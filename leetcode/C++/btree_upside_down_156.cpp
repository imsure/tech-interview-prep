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

// DFS approach: traverse the tree along the left subtrees and pass down the parent
// node until reaching the left-mode leaf node, this would be the root node for the
// upsidedown tree, and we move parent to new root's right and parent->right to new root's left.

// If root is not a leaf node, we know that this root

class Solution {
private:
  void _upsideDownBinaryTree(TreeNode* root, TreeNode* parent, TreeNode*& newRoot) {
    if (!root->left && !root->right) { // leaf node
      newRoot = root;
      root->right = parent;
      root->left = parent->right;
      parent->left = nullptr;
      parent->right = nullptr;
    } else {
      _upsideDownBinaryTree(root->left, root, newRoot);
      // upon returning, parent->left becomes root, and we put parent
      if (parent) {
        root->left = parent->right;
        root->right = parent;
        parent->left = nullptr;
        parent->right = nullptr;
      }
    }
  }

public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return root;
    TreeNode* newRoot;
    _upsideDownBinaryTree(root, nullptr, newRoot);
    return newRoot;
  }
};

int main()
{
  Solution sol;
}
