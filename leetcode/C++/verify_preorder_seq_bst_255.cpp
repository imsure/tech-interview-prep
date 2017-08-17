#include "common.hpp"

class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int n = preorder.size();
    if (n < 2) return true;

    stack<int> s;
    int root;
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

int main()
{
  Solution sol;
}
