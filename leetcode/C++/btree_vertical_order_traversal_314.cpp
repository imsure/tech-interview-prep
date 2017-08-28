#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// incorrect solution: didn't consider the traversal order must be
// from top to bottom.

class Solution {
private:
  void inorder(TreeNode* root, unordered_map<int, vector<int>>& col2vals,
               int& min_col_num, int& max_col_num, int cur_col_num) {
    if (!root) return;

    min_col_num = min(min_col_num, cur_col_num);
    max_col_num = max(max_col_num, cur_col_num);

    col2vals[cur_col_num].push_back(root->val);

    if (root->left) inorder(root->left, col2vals, min_col_num, max_col_num, cur_col_num - 1);
    if (root->right) inorder(root->right, col2vals, min_col_num, max_col_num, cur_col_num + 1);
  }

public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    unordered_map<int, vector<int>> col2vals;

    int min_col_num = std::numeric_limits<int>::max();
    int max_col_num = std::numeric_limits<int>::min();

    inorder(root, col2vals, min_col_num, max_col_num, 0);

    if (!col2vals.empty()) {
      for (int i = min_col_num; i <= max_col_num; ++i) {
        res.emplace_back(col2vals[i]);
      }
    }

    return res;
  }
};


class Solution2 {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    unordered_map<int, vector<int>> col2vals;

    int min_col_num = std::numeric_limits<int>::max();
    int max_col_num = std::numeric_limits<int>::min();
    int col_num = 0;
    queue<pair<TreeNode*, int>> cur_level;

    cur_level.push(std::make_pair(root, col_num));

    int sz;
    pair<TreeNode*, int> elem;
    TreeNode* node;
    while (!cur_level.empty()) {
      sz = cur_level.size();
      while (sz--) {
        elem = cur_level.front();
        cur_level.pop();
        node = elem.first;
        col_num = elem.second;
        col2vals[col_num].push_back(node->val);

        min_col_num = min(min_col_num, col_num);
        max_col_num = max(max_col_num, col_num);

        if (node->left) cur_level.push(std::make_pair(node->left, col_num - 1));
        if (node->right) cur_level.push(std::make_pair(node->right, col_num + 1));
      }
    }

    if (!col2vals.empty()) {
      for (int i = min_col_num; i <= max_col_num; ++i) {
        res.emplace_back(col2vals[i]);
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
}
