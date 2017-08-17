#include "common.hpp"

// keep a stack of nodes while still in the left subtree, if we encounter
// a node that is > the top node in the stack, pop up all the smaller ancestor
// until stack becomes empty or the popped value is > the current node we see.
// This popped value should be the predecessor of the current node, thus can be
// used as the lower bound, since we are now in the right subtree.

class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int n = preorder.size();
    if (n < 2) return true;

    stack<int> s;
    int cur_pred = numeric_limits<int>::min();

    for (int i = 0; i < n; ++i) {
      if (s.empty() || preorder[i] < s.top()) {
        // current node must be great than its predecessor
        if (preorder[i] < cur_pred) return false;
        s.push(preorder[i]);
      } else {
        while (!s.empty() && s.top() < preorder[i]) {
          cur_pred = s.top();
          s.pop();
        } // current node preorder[i] is the right child of cur_pred
        s.push(preorder[i]);
      }
    }

    return true;
  }
};

// same idea as above, but abusing the given array to avoid using extra space
// O(n) time O(1) space solution

class Solution2 {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int i = -1;
    int cur_pred = numeric_limits<int>::min();
    for (int node : preorder) {
      if (node < cur_pred) return false;
      while (i >= 0 && node > preorder[i]) {
        cur_pred = preorder[i--];
      }
      preorder[++i] = node;
    }

    return true;
  }
};

int main()
{
  Solution sol;
}
