#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Note: Recursive solution is trivial, could you do it iteratively?

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<pair<TreeNode*, bool>> stk;
    TreeNode* cur_node = root;

    while (!stk.empty() || cur_node) {
      if (cur_node) { // push to stack and move on to its left
        stk.push(make_pair(cur_node, false));
        cur_node = cur_node->left;
      } else { // get the top node from the stack and move on to its right
        if (stk.top().second == false) { // go to right subtree first
          cur_node = stk.top().first->right;
          stk.top().second = true; // mark true as right subtree has been visited
        } else {
          res.push_back(stk.top().first->val);
          stk.pop();
          // cur_node = nullptr;
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
}
