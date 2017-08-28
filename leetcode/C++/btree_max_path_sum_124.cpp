#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// incorrect solution

class Solution {
private:
  // max path sum that goes through the root
  int maxPathSum(TreeNode* root, int& max_path_sum) {
    if (!root) return 0;

    int path_sum = root->val;
    int path_sum_left = maxPathSum(root->left, max_path_sum);
    int path_sum_right = maxPathSum(root->right, max_path_sum);

    if (path_sum_left > 0) path_sum += path_sum_left;
    if (path_sum_right > 0) path_sum += path_sum_right;

    max_path_sum = max(max_path_sum, path_sum);

    return path_sum;
  }

public:
  int maxPathSum(TreeNode* root) {
    if (!root) return std::numeric_limits<int>::min();

    int max_path_sum = std::numeric_limits<int>::min();
    maxPathSum(root, max_path_sum);

    return max_path_sum;
  }
};


class Solution2 {
private:
  // max path sum that goes through the root
  int maxPathSum(TreeNode* root, int& max_path_sum) {
    if (!root) return 0;

    int path_sum = root->val;
    int path_sum_left = maxPathSum(root->left, max_path_sum);
    int path_sum_right = maxPathSum(root->right, max_path_sum);

    if (path_sum_left > 0) path_sum += path_sum_left;
    if (path_sum_right > 0) path_sum += path_sum_right;

    max_path_sum = max(max_path_sum, path_sum);

    int ret_sum = (path_sum_left > 0 && path_sum_right > 0) ? (path_sum_left > path_sum_right) ?
      root->val + path_sum_left : root->val + path_sum_right : path_sum;

    return ret_sum;
  }

public:
  int maxPathSum(TreeNode* root) {
    if (!root) return std::numeric_limits<int>::min();

    int max_path_sum = std::numeric_limits<int>::min();
    maxPathSum(root, max_path_sum);

    return max_path_sum;
  }
};

int main()
{
  Solution sol;
}
