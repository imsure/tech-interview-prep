#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// iterative solution: check the tree level by level to see if all levels
// are symmetric. Use a deque, push nodes (right to left) on the left subtree
// to the front of the deque and push nodes (left to right) on the right subtree
// to the back of the deque. Then for each pair of two nodes (one from front, one
// from back), check if they match.

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


// recursive solution: for the two subtrees L (contains root r1 and two subtrees L1 and R1)
// and R (contains root r2 and two subtrees L2 and R2) to be symmetric,
// they must 1) r1 == r2 and 2) L1 and R2 are symmetric as well as R1 and L2.

//    r1     |      r2
//   /  \    |     /  \
//  L1  R1   |    L2  R2


class Solution2 {
public:
  bool isSymmetric(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->val == root2->val) && isSymmetric(root1->left, root2->right)
      && isSymmetric(root1->right, root2->left);
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
  }
};

int main()
{
}
