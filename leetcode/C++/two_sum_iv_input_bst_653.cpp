#include "common.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time: O(NlogN), total n nodes to be traversed, and each search takes logN time
// space: O(1)
// runtime: 35ms

class Solution {
private:
  bool _findTarget(TreeNode* root, int k) {
    if (!root) return false;
    return search(_root, k - root->val, root) ? true : _findTarget(root->left, k) || _findTarget(root->right, k);
  }

  bool search(TreeNode* root, int target, TreeNode* excluded) {
    if (!root) return false;
    if (root->val == target && root != excluded) return true;
    return target < root->val ? search(root->left, target, excluded) : search(root->right, target, excluded);
  }

public:
  bool findTarget(TreeNode* root, int k) {
    _root = root;
    return _findTarget(root, k);
  }

private:
  TreeNode* _root;
};


// DFS + Set

// init a set to hold values in the tree.
// traverse the tree, for each node, look into the map to see if k - node.value is
// in the set or not, if yes, that means there exists a pair (node.value, k - node.value)
// in the tree that sums up to k. otherwise continue the process of the traversal.

// time: O(n)
// space: O(n)
// runtime: 53ms

class Solution2 {
public:
  bool findTarget(TreeNode* root, int k) {
    if (!root) return false;

    if (vals.count(k - root->val)) return true;
    vals.insert(root->val);
    if (root->left && findTarget(root->left, k)) return true;
    if (root->right && findTarget(root->right, k)) return true;

    return false;
  }

private:
  unordered_set<int> vals;
};


// in order traversal + vector + two pointers

// In order traverse the bst and store the values into a vector (ordered)

// use two pointers, one starting from the beginning of vector and one starts at
// the end, both moving towards each other. There are 3 cases to be considered:
// - the sum of the two values pointed by two pointers equals to k, then return true;
// - the sum of the two values pointed by two pointers less than k, then move the first pointer one step forward;
// - the sum of the two values pointed by two pointers greater than k, then move the second pointer one step backwards;
// stop when two pointers cross each other

// time: O(n)
// space: O(n)
// runtime: 35

class Solution3 {
private:
  void inorder(TreeNode* root, vector<int>& values) {
    if (!root) return;

    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
  }

public:
  bool findTarget(TreeNode* root, int k) {
    if (!root) return false;

    vector<int> values;
    inorder(root, values);

    int lo = 0, hi = values.size() - 1;
    int sum;
    while (lo < hi) {
      sum = values[lo] + values[hi];
      if (sum == k) return true;
      else if (sum < k) ++lo;
      else --hi;
    }

    return false;
  }
};


// DFS + Set

// init a set to hold values in the tree.
// traverse the tree, for each node, look into the map to see if k - node.value is
// in the set or not, if yes, that means there exists a pair (node.value, k - node.value)
// in the tree that sums up to k. otherwise continue the process of the traversal.

// time: O(n)
// space: O(n)
// runtime: 53ms

class Solution4 {
private:
  bool findTarget(TreeNode* root, int k, unordered_set<int>& vals) {
    if (!root) return false;

    if (vals.count(k - root->val)) return true;
    vals.insert(root->val);
    if (root->left && findTarget(root->left, k, vals)) return true;
    if (root->right && findTarget(root->right, k, vals)) return true;

    return false;
  }

public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> vals;
    return findTarget(root, k, vals);
  }
};

int main()
{
  Solution sol;
}
