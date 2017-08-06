#include "common.hpp"

/*
 * Find the 2nd largest node in a binary search tree, assuming tree has
 * at least two nodes.
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Given a bst tree, to find its 2nd largest node, there are following 3 cases to consider:
// - if tree has no right subtree, then the 2nd largest node would be the largest node
//   of tree.left since tree.root is the largest node of the tree.
// - if tree has right subtree with depth > 1, then the 2nd largest node would the 2nd largest node
//   of tree.right, so we can find it recursively.
// - if tree has right subtree with depth == 1 (only has a leaf node), then the 2nd largest node would
//   be tree.root.

class Solution {
public:
  int largestNode(TreeNode* root) {
    if (!root) return std::numeric_limits<int>::min();

    if (root->right) return largestNode(root->right);
    else return root->val;
  }
};

// iterative

class Solution2 {
public:
  int largestNode(TreeNode* root) {
    if (!root) return std::numeric_limits<int>::min();

    while (root->right) {
      root = root->right;
    }

    return root->val;
  }

  int secondLargestNode(TreeNode* root) {
    if (root->right) {
      if (root->right->left == nullptr && root->right->right == nullptr)
        return root->val;
      else
        return secondLargestNode(root->right);
    } else {
      return largestNode(root->left);
    }
  }
};

void insertNode(TreeNode*& root, int val)
{
  if (!root) {
    root = new TreeNode(val);
    return;
  }

  if (root->val >= val) insertNode(root->left, val);
  else insertNode(root->right, val);
}

TreeNode* buildBst(vector<int>& vals)
{
  TreeNode* root = nullptr;
  int len = vals.size();
  for (int i = 0; i < len; ++i) {
    insertNode(root, vals[i]);
  }
  return root;
}

// in order
void printBst(TreeNode* root)
{
  if (!root) return;
  if (!root->left && !root->right) {
    cout << root->val << ',';
    return;
  }

  if (root->left) printBst(root->left);
  cout << root->val << ',';
  if (root->right) printBst(root->right);
}

int main()
{
  Solution2 sol;

  vector<int> vals1 {6, 4, 3, 5, 8, 7, 9}; // balanced
  TreeNode* t1 = buildBst(vals1);
  printBst(t1);
  cout << endl;
  cout << sol.secondLargestNode(t1) << endl; // expected: 8

  vector<int> vals2 {6, 9}; // single node
  TreeNode* t2 = buildBst(vals2);
  printBst(t2);
  cout << endl;
  cout << sol.secondLargestNode(t2) << endl; // expected: 6

  vector<int> vals3 {6, 4, 3, 2, 1}; // left tilt
  TreeNode* t3 = buildBst(vals3);
  printBst(t3);
  cout << endl;
  cout << sol.secondLargestNode(t3) << endl; // expected: 4

  vector<int> vals4 {6, 7, 8, 9, 10}; // right tilt
  TreeNode* t4 = buildBst(vals4);
  printBst(t4);
  cout << endl;
  cout << sol.secondLargestNode(t4) << endl; // expected: 9

  vector<int> vals5 {6, 5, 8, 7, 9, 12, 13, 15}; // mixed1
  TreeNode* t5 = buildBst(vals5);
  printBst(t5);
  cout << endl;
  cout << sol.secondLargestNode(t5) << endl; // expected: 13

  vector<int> vals6 {10, 8, 7, 9, 1, 5, 11, 12, 13}; // mixed1
  TreeNode* t6 = buildBst(vals6);
  printBst(t6);
  cout << endl;
  cout << sol.secondLargestNode(t6) << endl; // expected: 12
}
