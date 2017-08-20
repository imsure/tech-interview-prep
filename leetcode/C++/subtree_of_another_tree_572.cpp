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
  void findRoot(TreeNode* s, int val, vector<TreeNode*>& roots) {
    if (!s) return;
    if (s->val == val) roots.push_back(s);

    findRoot(s->left, val, roots);
    findRoot(s->right, val, roots);
  }

  bool compareTwoTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (t1 && t2 && t1->val == t2->val) {
      return compareTwoTrees(t1->left, t2->left) && compareTwoTrees(t1->right, t2->right);
    }
    return false;
  }

public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    vector<TreeNode*> roots;
    findRoot(s, t->val, roots);

    if (roots.size() == 0) return false;

    for (int i = 0; i < roots.size(); ++i) {
      if (compareTwoTrees(roots[i], t)) return true;
    }

    return false;
  }
};

int main()
{
  Solution sol;
}
