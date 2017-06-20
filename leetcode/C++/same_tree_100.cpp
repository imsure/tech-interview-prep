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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    else if (!p && q) return false;
    else if (p && !q) return false;
    else {
      if (p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
      } else {
        return false;
      }
    }
  }
};

int main()
{
  Solution sol;
}
