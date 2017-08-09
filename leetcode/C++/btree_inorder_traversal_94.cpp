#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Note: Recursive solution is trivial, could you do it iteratively?

// corner case: if it is an empty tree, return immediately.
//
// use a stack to store visited nodes, each associated with a counter
// to keep track of how many times the node was read from the top of the stack.
//
// while stack is not empty:
//   get the top node, increment the counter by 1
//   if it is a leaf node, push its value to output vector and move on to the next iteration
//   if left is not empty and counter == 1 (means left has not been processed), push left to stack and move on to the next iteration
//   if left is not empty and counter > 1 (means left has been processed), push its value to output vector and deal with right
//   if left is empty, push its value to output vector and deal with right

class Solution {
private:
  bool isLeaf(TreeNode* node) {
    return node->left || node->right ? false : true;
  }

public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    if (!root) return res;

    stack<pair<TreeNode*, int>> nodes;
    nodes.push(std::make_pair(root, 0));

    pair<TreeNode*, int> cur_node;
    while (!nodes.empty()) {

      nodes.top().second += 1;
      cur_node = nodes.top();

      if (isLeaf(cur_node.first)) {
        res.push_back(cur_node.first->val);
        nodes.pop();
        continue;
      }

      if (cur_node.first->left && cur_node.second == 1) { // left subtree not visited
        nodes.push(std::make_pair(cur_node.first->left, 0));
        continue;
      } else if (cur_node.first->left && cur_node.second > 1) { // left subtree visited
        res.push_back(cur_node.first->val);
        nodes.pop();
      } else if (cur_node.first->left == nullptr) {
        res.push_back(cur_node.first->val);
        nodes.pop();
      }

      // deal with right subtree
      if (cur_node.first->right) {
        nodes.push(std::make_pair(cur_node.first->right, 0));
      }
    }

    return res;
  }
};

// concise & elegant solution

class Solution2 {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* cur_node = root;

    while (!stk.empty() || cur_node) {
      if (cur_node) { // push to stack and move on to its left
        stk.push(cur_node);
        cur_node = cur_node->left;
      } else { // pop the top node from the stack and move on to its right
        res.push_back(stk.top()->val);
        cur_node = stk.top()->right;
        stk.pop();
      }
    }

    return res;
  }
};

int main()
{
  Solution2 sol;
}
