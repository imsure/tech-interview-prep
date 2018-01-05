#include "common.hpp"

class Solution {
public:
  bool judgeCircle(string moves) {
    unordered_map<char, pair<int, int>> move_map;
    move_map['U'] = {-1, 0};
    move_map['D'] = {1, 0};
    move_map['L'] = {0, -1};
    move_map['R'] = {0, 1};

    pair<int, int> cur_pos {0, 0};
    for (char m : moves) {
      auto offset = move_map[m];
      cur_pos.first += offset.first;
      cur_pos.second += offset.second;
    }

    return cur_pos == make_pair(0, 0);
  }
};


class Solution2 {
public:
  bool judgeCircle(string moves) {
    unordered_map<char, int> move_count;
    move_count['U'] = 0;
    move_count['D'] = 0;
    move_count['L'] = 0;
    move_count['R'] = 0;

    for (char m : moves) move_count[m]++;

    return move_count['U'] == move_count['D'] &&
      move_count['L'] == move_count['R'];
  }
};


int main()
{
  Solution2 sol;
  cout << sol.judgeCircle("UD") << endl; // true
  cout << sol.judgeCircle("LL") << endl; // false
  cout << sol.judgeCircle("UDLR") << endl; // true
}
