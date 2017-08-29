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
  bool _findTarget(TreeNode* root, int k) {
    if (!root) return false;
    return search(_root, k - root->val, root) ? true : _findTarget(root->left, k) || _findTarget(root->right, k);
  }

  bool search(TreeNode* root, int target, TreeNode* excluded) {
    if (!root) return false;
    if (root->val == target && root != excluded) return true;
    return target < root->val ? search(root->left, target, excluded) : search(root->right, target, excluded);
  }

public:
  bool findTarget(TreeNode* root, int k) {
    _root = root;
    return _findTarget(root, k);
  }

private:
  TreeNode* _root;
};

int main()
{
  Solution sol;
}
