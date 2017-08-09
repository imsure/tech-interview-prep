#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// traverse the bst in order, return the kth order node (kth smallest).

// time: O(k)
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

// credit: https://discuss.leetcode.com/topic/17573/4-lines-in-c
// concise & elegant code!

// time: O(k)

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

// Follow up:
// What if the BST is modified (insert/delete operations) often
// and you need to find the kth smallest frequently?
// How would you optimize the kthSmallest routine?

// Extend the TreeNode with a count field to remember the total
// number of nodes of the tree. Then finding the kth smallest node
// will take just O(logN) time instead of linear time O(k).

struct TreeNodeWithCount {
  int val;
  int count;
  TreeNodeWithCount *left;
  TreeNodeWithCount *right;
  TreeNodeWithCount(int x) : val(x), count(1), left(NULL), right(NULL) {}
};

TreeNodeWithCount* buildTreeWithCount(TreeNode* root)
{
  if (!root) return nullptr;

  TreeNodeWithCount* _root = new TreeNodeWithCount(root->val);
  _root->left = buildTreeWithCount(root->left);
  _root->right = buildTreeWithCount(root->right);
  // this is wrong! Don't know why? but avoid this kind of code!
  // _root->count += _root->left ? _root->left->count : 0 + _root->right ? _root->right->count : 0;
  if (_root->left) _root->count += _root->left->count;
  if (_root->right) _root->count += _root->right->count;
  return _root;
}

class Solution3 {
private:
  int _kthSmallest(TreeNodeWithCount* root, int k) {
    if (!root) return std::numeric_limits<int>::min();

    if (root->left) {
      if (k <= root->left->count) return _kthSmallest(root->left, k);
      if (k == root->left->count + 1) return root->val;
      return _kthSmallest(root->right, k - 1 - root->left->count);
    } else {
      if (k == 1) return root->val;
      return _kthSmallest(root->right, k - 1);
    }
  }

public:
  int kthSmallest(TreeNode* root, int k) {
    TreeNodeWithCount* root2 = buildTreeWithCount(root);
    return _kthSmallest(root2, k);
  }
};

int main()
{
  Solution3 sol;
}
