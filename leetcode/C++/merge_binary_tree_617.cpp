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

int main()
{
}
