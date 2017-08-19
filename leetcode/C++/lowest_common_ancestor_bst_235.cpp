#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Walk down the tree as long as p and q are in the same subtree. If one of them
// is the root or both of them are not in the same subtree, just return root.

// time: O(logN)
// space:

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return nullptr;

    if (root->val == p->val || root->val == q->val) return root;

    if ((root->val > p->val && root->val < q->val) ||
        (root->val < p->val && root->val > q->val)) return root;

    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

    return nullptr; // shouldn't be here!
  }
};

// slightly optimized version

class Solution2 {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return nullptr;

    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

    return root;
  }
};

int main()
{
  Solution sol;
}
