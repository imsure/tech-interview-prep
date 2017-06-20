#include "common.hpp"

// time:
// space:
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> group_by_char;
    for (const char c : magazine) {
      if (group_by_char.find(c) == group_by_char.end()) {
        group_by_char[c] = 1;
      } else {
        group_by_char[c] += 1;
      }
    }

    for (const char c : ransomNote) {
      if (group_by_char.find(c) == group_by_char.end()) {
        return false;
      } else {
        if (group_by_char[c] < 1) {
          return false;
        } else {
          group_by_char[c] -= 1;
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution sol;
  cout << std::boolalpha << sol.canConstruct("aa", "aab") << endl;
  cout << std::boolalpha << sol.canConstruct("abc", "aab") << endl;
}
