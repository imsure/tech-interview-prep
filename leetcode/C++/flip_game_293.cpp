#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> moves {};

    for (int i = 0; i < (int)(s.size()) - 1; ++i) {
      if (s[i] == '+' && s[i+1] == '+') {
        string m {s};
        m[i] = m[i+1] = '-';
        moves.push_back(m);
      }
    }
    return moves;
  }
};

int main()
{
  Solution sol;
  //vector<string> res = sol.generatePossibleNextMoves("++++");
  vector<string> res = sol.generatePossibleNextMoves("");
  for (const auto& s : res) {
    cout << s << endl;
  }
}
