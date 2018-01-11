#include "common.hpp"

// Linear Scan

// time:
// space:

class Solution {
public:
  int romanToInt(string s) {
    if (s.size() == 0) return 0;

    unordered_map<char, int> table;
    table.insert({'I', 1});
    table.insert({'V', 5});
    table.insert({'X', 10});
    table.insert({'L', 50});
    table.insert({'C', 100});
    table.insert({'D', 500});
    table.insert({'M', 1000});

    int ans = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
      int val = table[s[i]];
      int next_val = table[s[i+1]];
      if (val >= next_val) ans += val;
      else ans -= val;
    }
    ans += table[s[s.size()-1]];
    return ans;
  }
};


// State Machine

enum State {
  I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
};

class Solution2 {
public:
  int romanToInt(string s) {
    if (s.size() == 0) return 0;

    int ans = 0;
    unordered_map<char, State> table;
    table['I'] = State::I;
    table['V'] = State::V;
    table['X'] = State::X;
    table['L'] = State::L;
    table['C'] = State::C;
    table['D'] = State::D;
    table['M'] = State::M;

    State prev_state = table[s[0]];
    State cur_state = prev_state;

    for (int i = 1; i < s.size(); ++i) {
      cur_state = table[s[i]];
      switch(cur_state) {
      case State::I:
        ans += prev_state; // any states to state I would incur an increase
        break;
      case State::V:
        if (prev_state >= State::V) ans += prev_state;
        else ans -= prev_state;
        break;
      case State::X:
        if (prev_state >= State::X) ans += prev_state;
        else ans -= prev_state;
        break;
      case State::L:
        if (prev_state >= State::L) ans += prev_state;
        else ans -= prev_state;
        break;
      case State::C:
        if (prev_state >= State::C) ans += prev_state;
        else ans -= prev_state;
        break;
      case State::D:
        if (prev_state >= State::D) ans += prev_state;
        else ans -= prev_state;
        break;
      case State::M:
        if (prev_state >= State::M) ans += prev_state;
        else ans -= prev_state;
        break;
      default: break;
      }
      prev_state = cur_state;
    }

    return ans + cur_state;
  }
};


// Simplifed State Machine

class Solution3 {
public:
  int romanToInt(string s) {
    if (s.size() == 0) return 0;

    int ans = 0;
    unordered_map<char, State> table;
    table['I'] = State::I;
    table['V'] = State::V;
    table['X'] = State::X;
    table['L'] = State::L;
    table['C'] = State::C;
    table['D'] = State::D;
    table['M'] = State::M;

    State prev_state = table[s[0]];
    State cur_state = prev_state;

    for (int i = 1; i < s.size(); ++i) {
      cur_state = table[s[i]];
      if (prev_state >= cur_state) ans += prev_state;
      else ans -= prev_state;

      prev_state = cur_state;
    }

    return ans + cur_state;
  }
};


int main()
{
  Solution3 sol;
  cout << sol.romanToInt("LXXXIX") << endl; // 89
  cout << sol.romanToInt("VIII") << endl; // 8
  cout << sol.romanToInt("XCIX") << endl; // 99
  cout << sol.romanToInt("D") << endl; // 100
  cout << sol.romanToInt("MMMDID") << endl; // 3999
}
