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
  void findPathSum(TreeNode* root, int sum) {
    if (!root) return;

    if (root->val == sum) ++pathCount;

    findPathSum(root->left, sum - root->val);
    findPathSum(root->right, sum - root->val);
  }

  void _pathSum(TreeNode* root, int sum) {
    if (!root) return;
    findPathSum(root, sum);
    _pathSum(root->left, sum);
    _pathSum(root->right, sum);
  }

public:
  int pathSum(TreeNode* root, int sum) {
    _pathSum(root, sum);
    return pathCount;
  }

private:
  int pathCount = 0;
};


class Solution2 {
private:
  int findPath(TreeNode* root, int sum) {
    if (!root) return 0;

    int count = 0;
    if (root->val == sum) ++count;

    count += findPath(root->left, sum - root->val);
    count += findPath(root->right, sum - root->val);
    return count;
  }

public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;

    int count = 0;
    count += findPath(root, sum);
    count += pathSum(root->left, sum);
    count += pathSum(root->right, sum);

    return count;
  }
};


class Solution3 {
private:
  int findPath(TreeNode* root, int sum, int prev_sum,
               unordered_map<int, int>& prefix_sums) {
    if (!root) return 0;

    int count = 0;
    int cur_sum = prev_sum + root->val;
    int diff = cur_sum - sum;
    if (prefix_sums.find(diff) != prefix_sums.end()) {
      count += prefix_sums[diff];
    }
    prefix_sums[cur_sum] += 1;

    count += findPath(root->left, sum, cur_sum, prefix_sums);
    count += findPath(root->right, sum, cur_sum, prefix_sums);
    prefix_sums[cur_sum] -= 1;
    return count;
  }

public:
  int pathSum(TreeNode* root, int sum) {
    unordered_map<int, int> prefix_sums;
    prefix_sums[0] = 1;
    return findPath(root, sum, 0, prefix_sums);
  }
};

int main()
{
  Solution sol;
}
