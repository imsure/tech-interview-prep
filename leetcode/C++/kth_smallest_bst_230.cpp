#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// traverse the bst in order, return the kth order node (kth smallest).

// time:
// space:

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    if (!root->left && !root->right) {
      if (++order == k) return root->val;
      else return std::numeric_limits<int>::min();
    }

    if (root->left) {
      int ret = kthSmallest(root->left, k);
      if (ret != std::numeric_limits<int>::min()) return ret;
    }

    if (++order == k) return root->val;

    if (root->right) {
      int ret = kthSmallest(root->right, k);
      if (ret != std::numeric_limits<int>::min()) return ret;
    }

    return std::numeric_limits<int>::min();
  }

private:
  int order = 0;
};

// concise & elegant code!

class Solution2 {
private:
  int _kthSmallest(TreeNode* root, int& k) {
    if (root) {
      int x = _kthSmallest(root->left, k);
      return !k ? x : !--k ? root->val : _kthSmallest(root->right, k);
    }
  }

public:
  int kthSmallest(TreeNode* root, int k) {
    return _kthSmallest(root, k);
  }
};

int main()
{
  Solution2 sol;
}
