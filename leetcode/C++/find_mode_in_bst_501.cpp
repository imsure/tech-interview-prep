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
  vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> val_counts;
    int max_count = numeric_limits<int>::min();

    stack<TreeNode*> stk;
    TreeNode* cur_node = root;
    while (!stk.empty() || cur_node) {
      if (cur_node) { // push to stack and move on to its left
        stk.push(cur_node);
        cur_node = cur_node->left;
      } else { // pop the top node from the stack and move on to its right
        val_counts[stk.top()->val] += 1;
        max_count = max(max_count, val_counts[stk.top()->val]);
        cur_node = stk.top()->right;
        stk.pop();
      }
    }

    vector<int> res;
    for (const auto& keyval : val_counts) {
      if (keyval.second == max_count) res.push_back(keyval.first);
    }

    return res;
  }
};

// Use two-pass traversal to avoid using extra space, first traverse the tree to find out
// the number of occurrences of a mode. Then traverse the tree again
// to gather all modes.

// Verbose and Not efficient! See Solution3

class Solution2 {
private:
  // pre-order
  int countOccurrence(TreeNode* root, int val) {
    if (!root) return 0;

    int count = root->val == val ? 1 : 0;
    if (root->left) count += countOccurrence(root->left, val);
    if (root->right) count += countOccurrence(root->right, val);

    return count;
  }

  // pre-order
  int findMaxOccur(TreeNode* root, TreeNode* parent) {
    if (!root) return 0;

    if (parent && root->val == parent->val)
      return max(findMaxOccur(root->left, root), findMaxOccur(root->right, root));

    int count = countOccurrence(root, root->val);
    int max_count = count;
    max_count = max(max_count, findMaxOccur(root->left, root));
    max_count = max(max_count, findMaxOccur(root->right, root));

    return max_count;
  }

  void gatherModes(TreeNode* root, TreeNode* parent, int max_count, vector<int>& modes) {
    if (!root) return;
    if (parent && root->val == parent->val) {
      gatherModes(root->left, root, max_count, modes);
      gatherModes(root->right, root, max_count, modes);
      return;
    }

    int count = countOccurrence(root, root->val);
    if (count == max_count) modes.push_back(root->val);
    gatherModes(root->left, root, max_count, modes);
    gatherModes(root->right, root, max_count, modes);
  }

public:
  vector<int> findMode(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    int max_occurrence = findMaxOccur(root, nullptr);
    gatherModes(root, nullptr, max_occurrence, res);
    return res;
  }
};

// A concise two-pass O(1) space solution
// credit: https://discuss.leetcode.com/topic/77372/11-liner-c-o-n-time-o-1-extra-space-in-order-traversal-detailed-explanation

class Solution3 {
private:
  // in order
  void findMaxCount(TreeNode* root, int& max_count, int& prev, int& count) {
    if (!root) return;

    findMaxCount(root->left, max_count, prev, count);
    root->val == prev ? ++count : count = 1;
    prev = root->val;
    max_count = max(max_count, count);
    findMaxCount(root->right, max_count, prev, count);
  }

  void gatherModes(TreeNode* root, int& max_count, int& prev, int& count, vector<int>& modes) {
    if (!root) return;

    gatherModes(root->left, max_count, prev, count, modes);
    root->val == prev ? ++count : count = 1;
    prev = root->val;
    if (count == max_count) modes.push_back(root->val);
    gatherModes(root->right, max_count, prev, count, modes);
  }

public:
  vector<int> findMode(TreeNode* root) {
    int max_count = 0, prev, count = 0;
    findMaxCount(root, max_count, prev, count);

    vector<int> modes;
    count = 0;
    gatherModes(root, max_count, prev, count, modes);

    return modes;
  }
};

int main()
{
  Solution sol;
}
