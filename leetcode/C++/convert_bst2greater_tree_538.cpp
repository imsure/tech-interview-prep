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
  void convertBST(TreeNode* root, int& prev_sum) {
    if (!root) return;

    convertBST(root->right, prev_sum);

    int tmp = root->val;
    root->val += prev_sum;
    prev_sum += tmp;

    convertBST(root->left, prev_sum);
  }

public:
  TreeNode* convertBST(TreeNode* root) {
    int prev_sum = 0;
    convertBST(root, prev_sum);

    return root;
  }
};

int main()
{
  Solution sol;
}
