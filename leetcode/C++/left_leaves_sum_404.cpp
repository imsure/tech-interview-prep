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
  bool isLeaf(TreeNode* node) {
    if (node) return node->left == NULL && node->right == NULL;
    else return false;
  }

public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }

    if (root->left && isLeaf(root->left)) {
      return root->left->val + sumOfLeftLeaves(root->right);
    } else {
      return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
  }
};

int main()
{
  Solution sol;
}
