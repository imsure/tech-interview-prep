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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> results;
    if (!root) return results;

    queue<TreeNode*> cur_level;
    cur_level.push(root);

    int sz;
    while (!cur_level.empty()) {
      vector<int> values;
      TreeNode* node;
      sz = cur_level.size();
      while (sz--) {
        node = cur_level.front();
        cur_level.pop();
        values.push_back(node->val);
        if (node->left) cur_level.push(node->left);
        if (node->right) cur_level.push(node->right);
      }
      results.push_back(values);
    }

    std::reverse(results.begin(), results.end());

    return results;
  }
};

int main()
{
  Solution sol;
}
