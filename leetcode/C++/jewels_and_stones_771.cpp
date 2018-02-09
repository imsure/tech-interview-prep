#include "common.hpp"


class Solution {
public:
  int numJewelsInStones(string J, string S) {
    set<char> jewels;
    int count = 0;
    for (char j : J) jewels.insert(j);
    for (char s : S) if (jewels.count(s)) ++count;
    return count;
  }
};


int main()
{
  Solution sol;
  cout << sol.numJewelsInStones("aA", "aAAbbbb") << endl;
  cout << sol.numJewelsInStones("z", "ZZ") << endl;
}
