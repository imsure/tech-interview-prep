#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> avgs;
    if (!root) return avgs;

    queue<TreeNode*> cur_level;
    cur_level.push(root);

    int sz, sz_bak;
    while (!cur_level.empty()) {
      double sum = 0;
      TreeNode* node;
      sz = cur_level.size();
      sz_bak = sz;
      while (sz--) {
        node = cur_level.front();
        cur_level.pop();
        sum += node->val;
        if (node->left) cur_level.push(node->left);
        if (node->right) cur_level.push(node->right);
      }
      avgs.push_back(sum / sz_bak);
    }

    return avgs;
  }
};

int main()
{
  Solution sol;
}
