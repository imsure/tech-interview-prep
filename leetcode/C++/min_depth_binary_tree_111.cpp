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
public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    if (root->left && root->right)
      return 1 + min(minDepth(root->left), minDepth(root->right));
    else if (root->left)
      return 1 + minDepth(root->left);
    else if (root->right)
      return 1 + minDepth(root->right);
    else
      return 1;
  }
};

int main()
{
  Solution sol;
}