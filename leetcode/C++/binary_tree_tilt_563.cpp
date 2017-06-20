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
  int getSum(TreeNode* root) {
    if (root == NULL) return 0;
    return root->val + getSum(root->left) + getSum(root->right);
  }

public:
  int findTilt(TreeNode* root) {
    if (root == NULL) return 0;

    int sum_left = getSum(root->left);
    int sum_right = getSum(root->right);
    int tilt = abs(sum_left - sum_right);

    return tilt + findTilt(root->left) + findTilt(root->right);
  }
};

int main()
{
  Solution sol;
}
