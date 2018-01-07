#include "../common.hpp"

class Solution {
public:
  vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    unordered_map<int, stack<int>> mapB;
    for (int i = 0; i < B.size(); ++i) {
      mapB[B[i]].push(i);
    }

    vector<int> ans;
    for (int i = 0; i < A.size(); ++i) {
      int pos = mapB[A[i]].top();
      mapB[A[i]].pop();
      ans.push_back(pos);
    }

    return ans;
  }
};


int main()
{
  vector<int> A {12, 28, 46, 32, 50};
  vector<int> B {50, 12, 32, 46, 28};
  Solution sol;
  auto res = sol.anagramMappings(A, B);
  for (int n : res) cout << n << ' ';
  cout << '\n';
}
