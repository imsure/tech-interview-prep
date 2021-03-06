#include "../common.hpp"

// 669. Trim a Binary Search Tree My SubmissionsBack to Contest
// User Accepted: 477
// User Tried: 551
// Total Accepted: 478
// Total Submissions: 680
// Difficulty: Easy
// Given a binary search tree and the lowest and highest boundaries as L and R,
// trim the tree so that all its elements lies in [L, R] (R >= L).
// You might need to change the root of the tree, so the result should
// return the new root of the trimmed binary search tree.

//   Example 1:
//   Input:
//    1
//   / \
//  0   2

//   L = 1
//   R = 2

//   Output:
//   1
//    \
//     2
//   Example 2:
//   Input:
//    3
//   / \
//  0   4
//   \
//    2
//   /
//  1

//   L = 1
//   R = 3

//   Output:
//     3
//    /
//   2
//  /
// 1

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// - if the root node is in between [L, R], then trim root->left &
//   root->right recursively.
// - if root node is < L, then trim root->right recursively.
// - if root node is > R, then trim root->left recursively

class Solution {
public:
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root || L > R) return root;

    if (root->val >= L && root->val <= R) {
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
      return root;
    } else if (root->val < L) {
      return trimBST(root->right, L, R);
    } else if (root->val > R) {
      return trimBST(root->left, L, R);
    }
  }
};


// improved code quality

class Solution2 {
public:
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root || L > R) return root;

    if (root->val < L) return trimBST(root->right, L, R);
    if (root->val > R) return trimBST(root->left, L, R);

    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};

int main()
{
  Solution sol;
}
