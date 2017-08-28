#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS solution

class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> avgs;
    if (!root) return avgs;

    queue<TreeNode*> cur_level;
    cur_level.push(root);

    int sz, sz_bak;
    while (!cur_level.empty()) {
      double sum = 0;
      TreeNode* node;
      sz = cur_level.size();
      sz_bak = sz;
      while (sz--) {
        node = cur_level.front();
        cur_level.pop();
        sum += node->val;
        if (node->left) cur_level.push(node->left);
        if (node->right) cur_level.push(node->right);
      }
      avgs.push_back(sum / sz_bak);
    }

    return avgs;
  }
};


// DFS solution

class Solution2 {
private:
  void dfs(TreeNode* root, int level, vector<double>& res, vector<int>& count) {
    if (!root) return;

    if (level <= res.size()) {
      res[level-1] += root->val;
      ++count[level-1];
    } else {
      res.push_back(root->val);
      count.push_back(1);
    }

    if (root->left) dfs(root->left, level+1, res, count);
    if (root->right) dfs(root->right, level+1, res, count);
  }

public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res; // sum of nodes on each level
    vector<int> count; // number of nodes on each level

    dfs(root, 1, res, count);

    for (int i = 0; i < res.size(); ++i) {
      res[i] /= count[i];
    }

    return res;
  }
};


int main()
{
  Solution sol;
}
