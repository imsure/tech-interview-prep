#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// traverse both trees in pre-order fashion (root, left, right).
// time: O(m+n), m and n corresponds to number of nodes in t1 and t2
// space: O(m+n), we are building a new tree here
// not a so good solution since we are building a complete new tree instead of
// merging in place. and the code is not quite readable.
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* tnew = new TreeNode(NULL);
    if (t1 && t2) { // both have subtrees
      tnew->val = t1->val + t2->val;
      tnew->left = mergeTrees(t1->left, t2->left);
      tnew->right = mergeTrees(t1->right, t2->right);
      return tnew;
    } else if (t1) { // t1 has subtree but t2 is a leaf node
      tnew->val = t1->val;
      tnew->left = mergeTrees(t1->left, NULL);
      tnew->right = mergeTrees(t1->right, NULL);
      return tnew;
    } else if (t2) { // t2 has subtree but t1 is a leaf node
      tnew->val = t2->val;
      tnew->left = mergeTrees(NULL, t2->left);
      tnew->right = mergeTrees(NULL, t2->right);
      return tnew;
    } else { // both NULL
      return NULL;
    }
  }
};


// credit: https://leetcode.com/articles/merge-two-binary-trees/
// pre-order traversal, merge two trees in place at t1.
// time: O(m), m is the minimum number of nodes of both trees, a total m nodes
//             needs to be traversed.
// space: O(m) ???
class Solution2 {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
  }
};

int main()
{
}
