#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  string _tree2str(TreeNode* t) {
    if (!t) return "";

    stringstream ss;
    ss << '(';
    ss << t->val;
    string sleft = _tree2str(t->left);
    string sright =  _tree2str(t->right);
    if (sleft.empty() && !sright.empty()) {
      ss << "()"; // place holder for left subtree
      ss << sright;
    } else {
      ss << sleft;
      ss << sright;
    }
    ss << ')';

    return ss.str();
  }

public:
  string tree2str(TreeNode* t) {
    if (!t) return "";

    stringstream ss;
    ss << t->val; // no () for the root node
    if (t->left == NULL && t->right != NULL) {
      ss << "()";
      ss << _tree2str(t->right);
    } else {
      ss << _tree2str(t->left);
      ss << _tree2str(t->right);
    }

    return ss.str();
  }
};

int main()
{
}
