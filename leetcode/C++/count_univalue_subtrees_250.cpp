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
  bool isUnivalSubtrees(TreeNode* root, int& count) {
    if (!root) return true;
    if (!root->left && !root->right) {
      ++count;
      return true;
    }

    bool l = isUnivalSubtrees(root->left, count);
    bool r = isUnivalSubtrees(root->right, count);
    if (l && r) {
      if (root->left && root->right && root->val == root->left->val
          && root->val == root->right->val) {
        ++count;
        return true;
      }
      else if (root->left && !root->right && root->val == root->left->val) {
        ++count;
        return true;
      }
      else if (root->right && !root->left && root->val == root->right->val) {
        ++count;
        return true;
      }
    }

    return false;
  }

public:
  int countUnivalSubtrees(TreeNode* root) {
    int count = 0;
    isUnivalSubtrees(root, count);
    return count;
  }
};

int main()
{
  Solution sol;
}
