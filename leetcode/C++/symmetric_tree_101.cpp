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
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    deque<TreeNode*> q;
    q.push_front(root->left);
    q.push_back(root->right);

    while (!q.empty()) {
      TreeNode* front_node = q.front();
      TreeNode* back_node = q.back();
      q.pop_front();
      q.pop_back();

      if ((front_node && !back_node) || (!front_node && back_node)) return false;
      if (!front_node && !back_node) continue;
      if (front_node->val != back_node->val) return false;

      q.push_front(front_node->right);
      q.push_front(front_node->left);
      q.push_back(back_node->left);
      q.push_back(back_node->right);
    }

    return true;
  }
};

int main()
{
}
