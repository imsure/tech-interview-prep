#include "../common.hpp"

// Brute force, ACed.
// time: O(M) where M is total length of all words, note that look up time for unordered set
// in C++ is constant in average.
// if using a set, time would be O(MlogN) where N is the # of words

class Solution {
public:
  string longestWord(vector<string>& words) {
    unordered_set<string> set;
    for (auto w : words) set.insert(w);

    string ans = "";
    for (auto w : words) {
      bool found = true;
      for (int i = w.size(); i > 0; --i) {
        if (!set.count(w.substr(0, i))) {
          found = false;
          break;
        }
      }
      if (found) {
        if (w.size() > ans.size()) ans = w;
        else if (w.size() == ans.size() && w < ans) ans = w;
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  // vector<string> words {"w","wo","wor","worl", "world"};
  vector<string> words {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  cout << sol.longestWord(words) << endl;
}
