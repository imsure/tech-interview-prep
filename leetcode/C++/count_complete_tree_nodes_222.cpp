#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n) brute force solution: Time Limit Exceeded

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};


// First find the height H of the tree by going all the way to the left
// given the definition of complete tree.
// Then look at the right subtree:
// - if its height is H-1, this implies that left subtree must be a perfect tree,
//   so we count all the node on left subtree (1 << h) - 1 plus 1 root node = 1 << h
//   and solve the same problem on the right subtree recursively.
// - if its height is H-2, this implies that right subtree must be a perfect tree,
//   we count its total node 1 << (h-1) - 1 plus 1 root node = 1 << (h - 1) and solve
//   the same problem on the left subtree recursively.

// time: O(logN) steps (each step halves the tree), each step spends O(logN) to compute height,
//       thus O(logN * logN)

class Solution2 {
private:
  int height(TreeNode* root) {
    // a single node tree has height of 0
    return root == nullptr ? -1 : 1 + height(root->left);
  }

public:
  int countNodes(TreeNode* root) {
    int h = height(root);
    return h < 0 ? 0 : height(root->right) == h - 1 ? (1 << h)  + countNodes(root->right)
      : (1 << (h-1)) + countNodes(root->left);
  }
};


// iterative solution: saves the call stack overhead and also
// avoids the recomputation of height in each step.

// time: O(logN)

class Solution3 {
private:
  int height(TreeNode* root) {
    // a single node tree has height of 0
    return root == nullptr ? -1 : 1 + height(root->left);
  }

public:
  int countNodes(TreeNode* root) {
    int count = 0;
    int h = height(root);
    int h_right;

    while (root) {
      h_right = height(root->right);
      if (h_right == h - 1) {
        count += (1 << h);
        root = root->right;
      } else { // h_right == h - 2
        count += (1 << (h - 1));
        root = root->left;
      }
      --h;
    }

    return count;
  }
};

int main()
{
  Solution sol;
}
