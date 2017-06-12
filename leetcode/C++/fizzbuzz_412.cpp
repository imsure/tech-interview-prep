#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<string> fizzBuzz(int n) {
    if (n <= 0) return vector<string> {};

    vector<string> res;
    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0 && i % 5 == 0) {
        res.push_back("FizzBuzz");
      } else if (i % 3 == 0) {
        res.push_back("Fizz");
      } else if (i % 5 == 0) {
        res.push_back("Buzz");
      } else {
        res.push_back(to_string(i));
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<string> res = sol.fizzBuzz(15);
  for (const auto& s : res)
    cout << s << endl;
}
