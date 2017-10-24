// Print out all subsets of a given set

#include "common.hpp"

// time: O(2^n), this is an exhaustive search algorithm. Each call
// makes two additional recursive calls and continues to a depth of n (size of input),
// thus the overall algorithm is 2^n (size of "power set").

// unfolding the recursion:
// suppose input is "abc":
//                                      "", "abc"
//                                     /        \
//                             "a", "bc"         "", "bc"
//                             /      \           /     \
//                       "ab", "c"  "a", "c"   "b", "c"  "", "c"
//                        /    \       /    \
//                 "abc",""  "ab","" "ac","" "a",""  "bc","", "b","", "","", "c",""

class Solution {
private:
  void recSubsets(string sofar, string rest) {
    if (rest.empty()) { // have exhausted all elements
      cout << sofar << endl;
      return;
    }
    // each time isolate one element from the given set

    // recursively find subsets that contains the isolated element
    recSubsets(sofar + rest[0], rest.substr(1));
    // recursively find subsets that do not contain the isolated element
    recSubsets(sofar, rest.substr(1));
  }

public:
  void subsets(string str) {
    recSubsets("", str);
  }
};

int main()
{
  Solution sol;
  sol.subsets("abcefghigklmnopq");
}
