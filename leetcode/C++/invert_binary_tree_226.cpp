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
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    if (root->left == NULL && root->right == NULL) return root;

    TreeNode* tmp = invertTree(root->right);
    root->right = invertTree(root->left);
    root->left = tmp;
    return root;
  }
};

int main()
{
  Solution sol;
}
