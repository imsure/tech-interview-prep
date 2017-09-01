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
  struct Counter {
    int inc_count;
    int dec_count;
    Counter() : inc_count(0), dec_count(0) {}
  };

private:
  Counter longestConsecutive(TreeNode* root, TreeNode* parent, int& max_count) {
    if (!root) return Counter();

    Counter left_cnt = longestConsecutive(root->left, root, max_count);
    Counter right_cnt = longestConsecutive(root->right, root, max_count);

    Counter cur_cnt;
    if (parent) {
      if (parent->val == root->val - 1) cur_cnt.inc_count = 1 + max(left_cnt.inc_count, right_cnt.inc_count);
      if (parent->val == root->val + 1) cur_cnt.dec_count = 1 + max(left_cnt.dec_count, right_cnt.dec_count);
    }


    max_count = max(max_count, max(1 + left_cnt.inc_count + right_cnt.dec_count,
                                   1 + left_cnt.dec_count + right_cnt.inc_count));

    return cur_cnt;
  }

public:
  int longestConsecutive(TreeNode* root) {
    int max_count = 0;
    longestConsecutive(root, nullptr, max_count);
    return max_count;
  }
};

int main()
{
  Solution sol;
}
