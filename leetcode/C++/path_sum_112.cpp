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
  bool hasPathSum(TreeNode* root, int sum, int cur_sum) {
    if (!root) return false;

    cur_sum += root->val;

    if (!root->left && !root->right) {
      if (sum == cur_sum) return true;
      return false;
    }

    bool leftHasPathSum = hasPathSum(root->left, sum, cur_sum);
    return leftHasPathSum ? true : hasPathSum(root->right, sum, cur_sum);
  }

public:
  bool hasPathSum(TreeNode* root, int sum) {
    return hasPathSum(root, sum, 0);
  }
};


// more concise code

class Solution2 {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (root->val == sum && !root->left && !root->right) return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};

int main()
{
  Solution sol;
}
