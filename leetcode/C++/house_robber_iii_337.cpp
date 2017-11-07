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
  int robExclude(TreeNode* root) {
    if (!root) return 0;
    return rob(root->left) + rob(root->right);
  }

public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    return max(root->val + robExclude(root->left) + robExclude(root->right),
               rob(root->left) + rob(root->right));
  }
};

int main()
{
  Solution sol;
}
