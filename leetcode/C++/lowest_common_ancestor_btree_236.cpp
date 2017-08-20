#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// if root equals to either p or q, return root immediately.
// otherwise, solve the same problem recursively by first going to the left subtree,
// and then to the right subtree. If one of them is in the left subtree and the other
// one is in the right subtree, that means root is the LCA. Else, if one of them is in
// the root of the left subtree and the other one is not in the right subtree, then return
// root of the left, vise versa for the right subtree.

// time: worse case O(N)
// space:

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p || root == q) return root;

    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);

    if (l && r) return root;
    return l ? l : r;
  }
};

int main()
{
  Solution sol;
}
