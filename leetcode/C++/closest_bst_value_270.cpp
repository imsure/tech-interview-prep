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

// The closest value to target is either the root or the closest
// in the apporpriate subtree.

class Solution2 {
public:
  int closestValue(TreeNode* root, double target) {
    double distance2root = abs(root->val - target);
    if (distance2root <= 0.5) return root->val;

    TreeNode* child = root->val > target ? root->left : root->right;
    if (child) {
      int closest_in_subtree = closestValue(child, target);
      return abs(closest_in_subtree - target) < distance2root ? closest_in_subtree : root->val;
    } else {
      return root->val;
    }
  }
};

int main()
{
  Solution sol;
}
