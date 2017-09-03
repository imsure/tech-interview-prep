#include "../common.hpp"

// 671. Second Minimum Node In a Binary Tree My SubmissionsBack to Contest
// User Accepted: 1319
// User Tried: 1563
// Total Accepted: 1339
// Total Submissions: 3256
// Difficulty: Easy
// Given a non-empty special binary tree consisting of nodes with the non-negative value,
// where each node in this tree has exactly two or zero sub-node.
// If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

//   If no such second minimum value exists, output -1 instead.

//   Example 1:
//   Input:
//      2
//     / \
//    2   5
//   / \
//  5   7

//   Output: 5
//   Explanation: The smallest value is 2, the second smallest value is 5.
//   Example 2:
//   Input:
//     2
//    / \
//   2   2

//   Output: -1
//   Explanation: The smallest value is 2, but there isn't any second smallest value.

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time: O(NlogN)
// space: O(N)

class Solution {
private:
  void preorder(TreeNode* root, vector<int>& list, int prev) {
    if (!root) return;
    if (root->val != prev) list.push_back(root->val);
    prev = root->val;
    preorder(root->left, list, prev);
    preorder(root->right, list, prev);
  }

public:
  int findSecondMinimumValue(TreeNode* root) {
    vector<int> list;
    preorder(root, list, -1);
    std::sort(list.begin(), list.end());

    if (list.size() < 2) return -1;
    return list[1];
  }
};


// use set instead of vector. set is ordered and automatically deals
// with duplicates.

// time: O(NlogN), set insertion is logN in average.
// space: O(N)

class Solution2 {
private:
  void preorder(TreeNode* root, set<int>& val_set) {
    if (!root) return;
    val_set.insert(root->val);
    preorder(root->left, val_set);
    preorder(root->right, val_set);
  }

public:
  int findSecondMinimumValue(TreeNode* root) {
    set<int> val_set;
    preorder(root, val_set);

    if (val_set.size() < 2) return -1;
    auto it = val_set.begin();
    ++it;
    return *it;
  }
};

// pre-order traverse the tree, and update both smallest and 2nd
// smallest value along the way.

// time: O(N)
// space: O(N)

class Solution3 {
private:
  void preorder(TreeNode* root, pair<int, int>& p) {
    if (!root) return;

    if (p.first < 0) {
      p.first = root->val;
    } else if (p.second < 0) {
      if (root->val < p.first) {
        p.second = p.first;
        p.first = root->val;
      } else if (root->val > p.first) {
        p.second = root->val;
      }
    } else {
      if (root->val < p.first) {
        p.second = p.first;
        p.first= root->val;
      } else if (root->val > p.first && root->val < p.second) {
        p.second = root->val;
      }
    }

    preorder(root->left, p);
    preorder(root->right, p);
  }

public:
  int findSecondMinimumValue(TreeNode* root) {
    pair<int, int> p (-1, -1);
    preorder(root, p);

    return p.second;
  }
};

int main()
{
  Solution sol;
}
