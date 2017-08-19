#include "common.hpp"

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

int main()
{
  Solution sol;
}
