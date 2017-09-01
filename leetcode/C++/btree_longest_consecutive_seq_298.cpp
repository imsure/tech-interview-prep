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
  int longestConsecutive(TreeNode* root, TreeNode* parent, int prev_count) {
    if (!root) return 0;

    int cur_count;
    if (parent && root->val == parent->val + 1) {
      cur_count = prev_count + 1;
    } else {
      cur_count = 1;
    }

    return max(cur_count, max(longestConsecutive(root->left, root, cur_count),
                              longestConsecutive(root->right, root, cur_count)));
  }

public:
  int longestConsecutive(TreeNode* root) {
    return longestConsecutive(root, nullptr, 0);
  }
};

int main()
{
  Solution sol;
}
