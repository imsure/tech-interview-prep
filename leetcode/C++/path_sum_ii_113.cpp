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
  void findPathSum(TreeNode* root, int sum, vector<vector<int>>& results) {
    if (!root) return;

    values.push_back(root->val);

    if (!root->left && !root->right && root->val == sum) {
      results.emplace_back(values);
    }

    findPathSum(root->left, sum - root->val, results);
    findPathSum(root->right, sum - root->val, results);
    values.pop_back();
  }

public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> results;
    findPathSum(root, sum, results);
    return results;
  }

private:
  vector<int> values;
};

int main()
{
  Solution sol;
}
