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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums, int low_index, int high_index) {
    if (low_index > high_index) return nullptr;

    int max_val = std::numeric_limits<int>::min(), max_index;
    for (int i = low_index; i <= high_index; ++i) {
      if (nums[i] > max_val) {
        max_val = nums[i];
        max_index = i;
      }
    }

    TreeNode* root = new TreeNode(max_val);
    root->left = constructMaximumBinaryTree(nums, low_index, max_index - 1);
    root->right = constructMaximumBinaryTree(nums, max_index + 1, high_index);

    return root;
  }

public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int len = nums.size();
    if (!len) return nullptr;

    return constructMaximumBinaryTree(nums, 0, len - 1);
  }
};

int main()
{
  Solution sol;
}
