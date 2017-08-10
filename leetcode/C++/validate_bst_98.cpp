#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  bool _isValidBST(TreeNode* root, int parent_val, int direction) {
    if (!root) return true; // empty tree is always valid

    // local check
    if (root->left && root->left->val >= root->val) return false;
    if (root->right && root->right->val <= root->val) return false;

    // global check
    if (direction < 0) {
      TreeNode* runner = root->right;
      while (runner) {
        if (runner->val >= parent_val) return false;
        else runner = runner->right;
      }
    } else {
      TreeNode* runner = root->left;
      while (runner) {
        if (runner->val <= parent_val) return false;
        else runner = runner->left;
      }
    }

    // left tree and right tree must be both valid
    return _isValidBST(root->left, root->val, -1) && _isValidBST(root->right, root->val, 1);
  }

public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true; // empty tree is always valid

    if (root->left && root->left->val >= root->val) return false;
    if (root->right && root->right->val <= root->val) return false;

    // left tree and right tree must be both valid
    return _isValidBST(root->left, root->val, -1) && _isValidBST(root->right, root->val, 1);
  }
};

int main()
{
  Solution sol;
}
