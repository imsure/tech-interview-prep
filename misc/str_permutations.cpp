// Print out all possible permutations of letters in a string

#include "common.hpp"

// Exhaustive recursion:
// if there is no more chars left for the current arrangement, then print
// for (every possible choice among the chars left for the arrangment) :
//     add the char to the arrangement so far and,
//     recursively arrange the remaining chars

class Solution {
private:
  void recPermute(string sofar, string rest) {
    if (rest.empty()) {
      cout << sofar << endl;
      return;
    }

    for (int i = 0; i < rest.size(); ++i) {
      string remaining = rest.substr(0, i) + rest.substr(i+1);
      recPermute(sofar + rest[i], remaining);
    }
  }

public:
  void permute(string str) {
    recPermute("", str);
  }
};

int main()
{
  Solution sol;
  sol.permute("abc");
}
