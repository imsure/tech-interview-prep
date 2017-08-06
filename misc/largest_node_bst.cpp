#include "common.hpp"

/*
 * Find the largest node in a binary search tree.
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// The largest node of a bst Tree is the largest node
// of its right subtree Tree.right if Tree has a right subtree,
// otherwise it's root node.

class Solution {
public:
  int largestNode(TreeNode* root) {
    if (!root) return std::numeric_limits<int>::min();

    if (root->right) return largestNode(root->right);
    else return root->val;
  }
};

class Solution2 {
public:
  int largestNode(TreeNode* root) {
    if (!root) return std::numeric_limits<int>::min();

    while (root->right) {
      root = root->right;
    }

    return root->val;
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
  cout << sol.largestNode(t1) << endl; // expected: 9

  vector<int> vals2 {6}; // single node
  TreeNode* t2 = buildBst(vals2);
  printBst(t2);
  cout << endl;
  cout << sol.largestNode(t2) << endl; // expected: 6

  vector<int> vals3 {6, 4, 3, 2, 1}; // left tilt
  TreeNode* t3 = buildBst(vals3);
  printBst(t3);
  cout << endl;
  cout << sol.largestNode(t3) << endl; // expected: 6

  vector<int> vals4 {6, 7, 8, 9, 10}; // right tilt
  TreeNode* t4 = buildBst(vals4);
  printBst(t4);
  cout << endl;
  cout << sol.largestNode(t4) << endl; // expected: 10

  vector<int> vals5 {6, 5, 8, 7, 9, 12, 12, 15}; // mixed1
  TreeNode* t5 = buildBst(vals5);
  printBst(t5);
  cout << endl;
  cout << sol.largestNode(t5) << endl; // expected: 15

  vector<int> vals6 {10, 8, 7, 9, 1, 5, 11, 12, 13}; // mixed1
  TreeNode* t6 = buildBst(vals6);
  printBst(t6);
  cout << endl;
  cout << sol.largestNode(t6) << endl; // expected: 13
}
