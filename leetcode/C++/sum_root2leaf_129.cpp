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
  void sumNumbers(TreeNode* root, int& sum, string str_val) {
    str_val.push_back(root->val + '0');

    if (!root->left && !root->right) {
      sum += stoi(str_val);
      return;
    }

    if (root->left) sumNumbers(root->left, sum, str_val);
    if (root->right) sumNumbers(root->right, sum, str_val);
  }

public:
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    sumNumbers(root, sum, "");

    return sum;
  }
};


// slightly optimized version

class Solution2 {
private:
  void sumNumbers(TreeNode* root, int& sum, int cur_val) {
    cur_val = cur_val * 10 + root->val;

    if (!root->left && !root->right) {
      sum += cur_val;
      return;
    }

    if (root->left) sumNumbers(root->left, sum, cur_val);
    if (root->right) sumNumbers(root->right, sum, cur_val);
  }

public:
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    sumNumbers(root, sum, 0);

    return sum;
  }
};

int main()
{
  Solution sol;
  stringstream ss;
  for (int i = 0; i < 10; ++i) ss << i;
  cout << ss.str() << endl;
  cout << stoi(ss.str()) << endl;
}
