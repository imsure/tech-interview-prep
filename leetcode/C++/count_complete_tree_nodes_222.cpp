#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n) solution: Time Limit Exceeded

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

class Solution2 {
private:
  int height(TreeNode* root) {
    // a single node tree has height of 0
    return root == nullptr ? -1 : 1 + height(root->left);
  }

public:
  int countNodes(TreeNode* root) {
    int h = height(root);
    return h < 0 ? 0 : height(root->right) == h - 1 ? (1 << h)  + countNodes(root->right)
      : (1 << (h-1)) + countNodes(root->left);
  }
};

int main()
{
  Solution sol;
}
