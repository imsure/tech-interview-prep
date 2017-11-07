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
    // return the max between including the root or not.
    return max(root->val + robExclude(root->left) + robExclude(root->right),
               rob(root->left) + rob(root->right));
  }
};


// improved to avoid redudant computations

class Solution2 {
private:
  int robExclude(TreeNode* root) {
    if (!root) return 0;
    return rob(root->left) + rob(root->right);
  }

public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    // return the max between including the root or not.
    int max_left_exclude = 0;
    int max_right_exclude = 0;
    int max_left = 0, max_right = 0;
    if (root->left) {
      max_left_exclude = robExclude(root->left);
      max_left = max(max_left_exclude, root->left->val + robExclude(root->left->left) + robExclude(root->left->right));
    }
    if (root->right) {
      max_right_exclude = robExclude(root->right);
      max_right = max(max_right_exclude, root->right->val + robExclude(root->right->left) + robExclude(root->right->right));
    }

    return max(root->val + max_left_exclude + max_right_exclude,
               max_left + max_right);
  }
};

int main()
{
  Solution sol;
}
