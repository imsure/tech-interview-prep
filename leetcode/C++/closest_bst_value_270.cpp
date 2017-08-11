#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    if (!root->left && !root->right) return root->val;

    if (abs(root->val - target) <= 0.5) return root->val;

    if (root->val < target) {
      if (root->right) {
        int closest_right = closestValue(root->right, target);
        if (abs(root->val - target) <= abs(closest_right - target))
          return root->val;
        else
          return closest_right;
      } else {
        return root->val;
      }
    }

    if (root->val > target) {
      if (root->left) {
        int closest_left = closestValue(root->left, target);
        if (abs(root->val - target) <= abs(closest_left - target))
          return root->val;
        else
          return closest_left;
      } else {
        return root->val;
      }
    }
  }
};

int main()
{
  Solution sol;
}
