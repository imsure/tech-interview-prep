#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time: exponential due to overlapping computations (similar like resurive solution for fibnacci nums)
// took 1042 ms to run.

class Solution {
private:
  int robExclude(TreeNode* root) {
    if (!root) return 0;
    return rob(root->left) + rob(root->right);
  }

public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    // return the max between including the root or not.
    return max(root->val + robExclude(root->left) + robExclude(root->right),
               rob(root->left) + rob(root->right));
  }
};


// improved to avoid redudant computations

class Solution2 {
private:
  int robExclude(TreeNode* root) {
    if (!root) return 0;
    return rob(root->left) + rob(root->right);
  }

public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    // return the max between including the root or not.
    int max_left_exclude = 0;
    int max_right_exclude = 0;
    int max_left = 0, max_right = 0;
    if (root->left) {
      max_left_exclude = robExclude(root->left);
      max_left = max(max_left_exclude, root->left->val + robExclude(root->left->left) + robExclude(root->left->right));
    }
    if (root->right) {
      max_right_exclude = robExclude(root->right);
      max_right = max(max_right_exclude, root->right->val + robExclude(root->right->left) + robExclude(root->right->right));
    }

    return max(root->val + max_left_exclude + max_right_exclude,
               max_left + max_right);
  }
};


// time: O(n), n is # of nodes

class Solution3 {
private:
  pair<int, int> _rob(TreeNode* root) {
    pair<int, int> res {0, 0};
    if (!root) return res;
    auto lres = _rob(root->left);
    auto rres = _rob(root->right);
    res.first = root->val + lres.second + rres.second; // value including root
    res.second = max(lres.first, lres.second) + max(rres.first, rres.second); // not including root
    return res;
  }

public:
  int rob(TreeNode* root) {
    auto res = _rob(root);
    return max(res.first, res.second);
  }
};


int main()
{
  Solution sol;
}
