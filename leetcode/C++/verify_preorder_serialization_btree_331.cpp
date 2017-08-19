#include "common.hpp"

// key observation: in a valid binary tree serialization:
// the number of '#' is always greater than the number of
// values by 1. So each value can be paired up with a '#',
// so if use a stack and scan left to right, when we see a
// value, push to the stack. when we see a '#', if the top
// of stack is also a '#', pop it out and aslo pop up the value
// following the '#', keep doing so until the top of the stack
// is not '#'. Push the '#' we saw onto the stack afterwards.
// In the end, the stack size should be 1 and the top of the stack
// should be '#'.

// Additional note: http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/bintree.html
// If we see null as leaf nodes, then the tree is a "strictly binary tree"
// (every non-leaf) nodes has non-empty left and right subtree. Then If we have
// N leaf nodes, there are N-1 non-leaf nodes.

class Solution {
public:
  bool isValidSerialization(string preorder) {
    stringstream ss(preorder);
    vector<string> nodes;

    string substr;
    while (ss.good()) {
      getline(ss, substr, ',');
      nodes.push_back(substr);
    }

    stack<string> st;
    int len = nodes.size();
    for (int i = 0; i < len; ++i) {
      while (!st.empty() && nodes[i].at(0) == '#' && st.top().at(0) == '#') {
        st.pop();
        if (st.empty()) return false;
        st.pop();
      }
      st.push(nodes[i]);
    }

    return st.size() == 1 && st.top().at(0) == '#' ? true : false;
  }
};


// Idea: the difference between total out degree and in degree of all nodes
// for a valid binary tree serialization should be 0 and it cannot be negative.

class Solution2 {
public:
  bool isValidSerialization(string preorder) {
    stringstream ss(preorder);
    vector<string> nodes;

    string substr;
    while (ss.good()) {
      getline(ss, substr, ',');
      nodes.push_back(substr);
    }

    int diff = 1; // 1 because the root node has in-degree = 0 and out-degree = 2
    int len = nodes.size();
    for (int i = 0; i < len; ++i) {
      if (--diff < 0) return false; // every node contribute to 1 in-degree
      if (nodes[i].at(0) != '#') diff += 2; // every non-leaf node contributes to 2 out-degree
    }

    return diff == 0;
  }
};


// a lightly optimized version

class Solution3 {
public:
  bool isValidSerialization(string preorder) {
    stringstream ss(preorder);

    int diff = 1; // 1 because the root node has in-degree = 0 and out-degree = 2
    string substr;
    while (ss.good()) {
      getline(ss, substr, ',');
      if (--diff < 0) return false; // every node contribute to 1 in-degree
      if (substr.at(0) != '#') diff += 2; // every non-leaf node contributes to 2 out-degree
    }

    return diff == 0;
  }
};

int main()
{
  Solution sol;
}
