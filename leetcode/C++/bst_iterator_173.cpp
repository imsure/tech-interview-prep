#include "common.hpp"

// Reuse the code from kth_smallest_bst_230.cpp, rebuild the
// tree with TreeNodeWithCount in constructor in O(n) time.
// Then next() runs in O(h) time and hasNext() runs in O(1) time.

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

class BSTIterator {
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
  BSTIterator(TreeNode *root) {
    rootWithCount = buildTreeWithCount(root);
    if (rootWithCount) nNode = rootWithCount->count;
    else nNode = 0;

    k = 1;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return k <= nNode;
  }

  /** @return the next smallest number */
  int next() {
    return _kthSmallest(rootWithCount, k++);
  }

private:
  TreeNodeWithCount* rootWithCount;
  int nNode;
  int k;
};

// utilize a stack, the next element is always on top of the stack.

class BSTIterator2 {
private:
  void setNextSmallest(TreeNode* root) {
    TreeNode* runner = root;
    while (runner) {
      stk.push(runner);
      runner = runner->left;
    }
  }

public:
  BSTIterator2(TreeNode *root) {
    setNextSmallest(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stk.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* nextSmallestNode = stk.top();
    stk.pop();
    setNextSmallest(nextSmallestNode->right);
    return nextSmallestNode->val;
  }

private:
  stack<TreeNode*> stk;
};

int main()
{
}
