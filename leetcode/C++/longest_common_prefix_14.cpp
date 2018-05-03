#include "common.hpp"


// Find the list of the common prefix P[1...m] between the two shortest strings. Then for
// each of the remaining strings S, check if P[i] is a prefix of S for 1 <= i <= m,
// if not, remove P[i] from the list.

// At the end, return the longest common prefix from P if any, otherwise return ""


class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    if (!len) return "";
    if (len == 1) return strs[0];

    unordered_set<string> prefix_set;
    int min_len1, min_len2;
    int min_index1, min_index2;

    min_len1 = min_len2 = numeric_limits<int>::max();
    for (int i = 0; i < strs.size(); ++i) {
      if (strs[i].size() <= min_len1) {
        min_len2 = min_len1;
        min_index2 = min_index1;
        min_len1 = strs[i].size();
        min_index1 = i;
      } else if (strs[i].size() < min_len2) {
        min_len2 = strs[i].size();
        min_index2 = i;
      }
    }

    if (min_len1 == 0) return "";

    for (int i = 0; i < min_len1; ++i) {
      string prefix = strs[min_index1].substr(0, i + 1);
      if (strs[min_index2].find(prefix) == 0) prefix_set.insert(prefix);
    }

    if (prefix_set.empty()) return "";

    for (int i = 0; i < strs.size(); ++i) {
      if (i == min_index1 || i == min_index2) continue;
      auto it = prefix_set.begin();
      while (it != prefix_set.end()) {
        string prefix = *it;
        if (strs[i].find(prefix) != 0) {
          it = prefix_set.erase(it);
          // cout << prefix << " erased\n";
        } else {
          ++it;
        }
      }
    }

    string ans;
    int max_len = 0;
    for (auto& prefix : prefix_set) {
      if (prefix.size() > max_len) {
        ans = prefix;
        max_len = prefix.size();
      }
    }
    return ans;
  }
};


// Line-up all string vertically and align left-most chars on the
// same column. Then scan each column from left to right. Stop when
// column have different chars or some cell is empty.

class Solution2 {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    string prefix = "";
    if (!len) return prefix;

    for (int col = 0; col < strs[0].size(); ++col) {
      char c = strs[0][col];
      for (int row = 1; row < len; ++row) {
        if (col == strs[row].size()) return prefix;
        if (c != strs[row][col]) return prefix;
      }
      prefix += c;
    }

    return prefix;
  }
};


int main()
{
  vector<string> strs {"flower","flow","flight"};
  // vector<string> strs {"dog","racecar","car"};
  Solution2 sol;
  cout << sol.longestCommonPrefix(strs) << endl;
}
