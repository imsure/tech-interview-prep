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
  int getMinimumDifference(TreeNode* root) {
    if (root == NULL) return numeric_limits<int>::max();
    if (root->left == NULL && root->right == NULL) return numeric_limits<int>::max();

    TreeNode* left_subtree = root->left;
    TreeNode* right_subtree = root->right;

    while (left_subtree && left_subtree->right) {
      left_subtree = left_subtree->right;
    }

    while (right_subtree && right_subtree->left) {
      right_subtree = right_subtree->left;
    }

    int min_diff;
    if (!left_subtree) {
      min_diff = abs(root->val - right_subtree->val);
    } else if (!right_subtree) {
      min_diff = abs(root->val - left_subtree->val);
    } else {
      min_diff = min(abs(root->val - left_subtree->val),
                     abs(root->val - right_subtree->val));
    }
    int min_diff2 = min(getMinimumDifference(root->left), getMinimumDifference(root->right));
    return min(min_diff, min_diff2);
  }
};

int main()
{
  Solution sol;
}
