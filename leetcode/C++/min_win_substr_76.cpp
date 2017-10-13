#include "common.hpp"

// Build a hashmap that maps each char in t to its position (init to -1) as appeared in s.
// Maintain two variables min_index and max_index to indicate the start and end position
// of the window.

// wrong attemp: doesnot handle t with repeated letters.

class Solution {
private:
  // check if the table is filled or not
  bool checkTable(unordered_map<char, int>& table) {
    bool table_filled = true;
    for (auto kv : table) {
      if (kv.second == -1) {
        table_filled = false; break;
      }
    }

    return table_filled;
  }

public:
  string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";

    unordered_set<char> tset;
    unordered_map<char, int> table;
    for (int i = 0; i < t.size(); ++i) {
      table[t[i]] = -1;
      tset.insert(t[i]);
    }

    bool table_full = false;
    int min_pos = numeric_limits<int>::max(), max_pos = numeric_limits<int>::min();
    for (int i = 0; i < s.size(); ++i) {
      if (tset.count(s[i])) {
        if (!table_full) {
          table[s[i]] = i;
          table_full = checkTable(table);

          if (table_full) {
            for (auto kv : table) {
              min_pos = min(min_pos, kv.second);
              max_pos = max(max_pos, kv.second);
            }
          }
        } else {
          table[s[i]] = i;
          int min_pos2 = numeric_limits<int>::max(), max_pos2 = numeric_limits<int>::min();
          for (auto kv : table) {
            min_pos2 = min(min_pos2, kv.second);
            max_pos2 = max(max_pos2, kv.second);
          }

          if (max_pos2 - min_pos2 < max_pos - min_pos) {
            min_pos = min_pos2;
            max_pos = max_pos2;
          }
        }
      }
    }

    return table_full ? s.substr(min_pos, max_pos - min_pos + 1) : "";
  }
};


class Solution2 {
public:
  string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";

    unordered_map<char, int> t_table;
    unordered_map<char, int> win;
    int letter_counter = 0;

    for (int i = 0; i < t.size(); ++i) {
      t_table[t[i]]++;
    }

    string ans = "";
    int min_len = numeric_limits<int>::max();
    for (int slow = 0, fast = 0; fast < s.size(); ++fast) {
      if (!t_table.count(s[fast])) continue;

      win[s[fast]]++;
      if (win[s[fast]] <= t_table[s[fast]]) {
        letter_counter++;
      }

      if (letter_counter >= t.size()) { // a cover window found
        // shrink the slow pointer to find the minimum window
        while (!t_table.count(s[slow]) || win[s[slow]] > t_table[s[slow]]) {
          --win[s[slow]];
          ++slow;
        }
        if (fast - slow + 1 < min_len) {
          ans = s.substr(slow, fast - slow + 1);
          min_len = fast - slow + 1;
        }
      }
    }

    return ans;
  }
};


int main()
{
  Solution2 sol;
  string s = "ADOBECODEBANC", t = "ABC";
  // string s = "aa", t = "aa";
  cout << sol.minWindow(s, t) << endl;
}
