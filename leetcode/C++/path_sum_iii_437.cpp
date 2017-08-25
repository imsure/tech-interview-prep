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
  void findPathSum(TreeNode* root, int sum) {
    if (!root) return;

    if (root->val == sum) ++pathCount;

    findPathSum(root->left, sum - root->val);
    findPathSum(root->right, sum - root->val);
  }

  void _pathSum(TreeNode* root, int sum) {
    if (!root) return;
    findPathSum(root, sum);
    _pathSum(root->left, sum);
    _pathSum(root->right, sum);
  }

public:
  int pathSum(TreeNode* root, int sum) {
    _pathSum(root, sum);
    return pathCount;
  }

private:
  int pathCount = 0;
};


class Solution2 {
private:
  int findPath(TreeNode* root, int sum) {
    if (!root) return 0;

    int count = 0;
    if (root->val == sum) ++count;

    count += findPath(root->left, sum - root->val);
    count += findPath(root->right, sum - root->val);
    return count;
  }

public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;

    int count = 0;
    count += findPath(root, sum);
    count += pathSum(root->left, sum);
    count += pathSum(root->right, sum);

    return count;
  }
};


int main()
{
  Solution sol;
}
