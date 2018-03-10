#include "common.hpp"


// Brute force:

class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    unordered_set<char> amap;
    for (char c : A) amap.insert(c);
    for (char c : B) if (!amap.count(c)) return -1;

    string a {A};
    int count = 1;
    while (true) {
      if (A.find(B) != string::npos) return count;
      A.append(a);
      ++count;
      if (A.size() > 3 * B.size()) break;
    }

    return -1;
  }
};


int main()
{
  Solution sol;
  cout << sol.repeatedStringMatch("abcd", "cdabcdab") << endl;
  cout << sol.repeatedStringMatch("bb", "bbbbbbb") << endl;
}
