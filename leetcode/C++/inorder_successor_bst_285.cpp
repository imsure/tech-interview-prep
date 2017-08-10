#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// starting from root, search for the smallest node that is greater than p

class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (!root || !p) return nullptr;

    TreeNode* successor = nullptr;
    TreeNode* node_runner = root;
    while (node_runner && node_runner != p) {
      if (node_runner->val < p->val) {
        node_runner = node_runner->right;
      } else {
        successor = node_runner;
        node_runner = node_runner->left;
      }
    }

    node_runner = p->right;
    while (node_runner) {
      successor = node_runner;
      node_runner = node_runner->left;
    }

    return successor;
  }
};

class Solution2 {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (!root || !p) return nullptr;

    TreeNode* successor = nullptr;
    TreeNode* node_runner = root;
    while (node_runner) {
      if (node_runner->val < p->val) {
        node_runner = node_runner->right;
      } else {
        successor = node_runner;
        node_runner = node_runner->left;
      }
    }

    return successor;
  }
};

int main()
{
  Solution sol;
}
