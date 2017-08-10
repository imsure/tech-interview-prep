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
  vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> val_counts;
    int max_count = numeric_limits<int>::min();

    stack<TreeNode*> stk;
    TreeNode* cur_node = root;
    while (!stk.empty() || cur_node) {
      if (cur_node) { // push to stack and move on to its left
        stk.push(cur_node);
        cur_node = cur_node->left;
      } else { // pop the top node from the stack and move on to its right
        val_counts[stk.top()->val] += 1;
        max_count = max(max_count, val_counts[stk.top()->val]);
        cur_node = stk.top()->right;
        stk.pop();
      }
    }

    vector<int> res;
    for (const auto& keyval : val_counts) {
      if (keyval.second == max_count) res.push_back(keyval.first);
    }

    return res;
  }
};

int main()
{
  Solution sol;
}
