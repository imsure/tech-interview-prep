#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time: O(logN)
// space:

class Solution {
  int _findFrequentTreeSum(TreeNode* root, int& maxFreq, unordered_map<int, int>& sumCount) {
    int lsum = 0, rsum = 0;
    if (root->left) {
      lsum = _findFrequentTreeSum(root->left, maxFreq, sumCount);
    }

    if (root->right) {
      rsum = _findFrequentTreeSum(root->right, maxFreq, sumCount);
    }

    int sum = lsum + rsum + root->val;
    sumCount[sum] += 1;
    maxFreq = max(maxFreq, sumCount[sum]);

    return sum;
  }

public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> results;
    if (!root) return results;

    unordered_map<int, int> sumCount;
    int maxFreq = 0;

    _findFrequentTreeSum(root, maxFreq, sumCount);

    for (const auto& keyval : sumCount) {
      if (keyval.second == maxFreq) results.push_back(keyval.first);
    }

    return results;
  }
};

int main()
{
  Solution sol;
}
