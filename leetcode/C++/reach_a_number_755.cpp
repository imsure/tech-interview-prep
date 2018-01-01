#include "common.hpp"

class Solution {
private:
  int move(int target, int step, int pos) {
    if (abs(pos) > abs(target)) return numeric_limits<int>::max();
    if (pos == target) return step;

    int right = move(target, step + 1, pos + step + 1);
    int left = move(target, step + 1, pos - step - 1);

    return min(right, left);
  }

public:
  int reachNumber(int target) {
    // if (target < 0) target = -target;
    return move(target, 0, 0);
  }
};

// BFS

class Solution2 {
public:
  int reachNumber(int target) {
    // if (target < 0) target = -target;
    int step = 1;
    vector<int> cur_level;
    cur_level.push_back(0);
    vector<int>& level = cur_level;
    while (true) {
      vector<int> next_level;
      for (int pos : cur_level) {
        if (pos + step == target || pos - step == target) return step;
        next_level.push_back(pos + step);
        next_level.push_back(pos - step);
      }
      ++step;
      level = next_level;
    }

    return -1;
  }
};


struct Move {
  int pos;
  int level;
public:
  Move() {}
  Move(int p, int l) : pos(p), level(l) {}
};

class Solution3 {
public:
  int reachNumber(int target) {
    int step = 0;
    queue<Move> cur_level;
    Move m (0, 1);
    cur_level.push(m);
    while (!cur_level.empty()) {
      Move m = cur_level.front();
      cur_level.pop();
      if (m.pos == target) {
        step = m.level - 1;
        break;
      }
      cur_level.push(Move(m.pos + m.level, m.level + 1));
      cur_level.push(Move(m.pos - m.level, m.level + 1));
    }

    return step;
  }
};


// 3: 1 + 2 = 3

// 4: 1 + 2 + 3 = 6 > 4, 6 - 4 = 2 which is even, 2/2 = 1 so make the first move from +1 to -1, -1 + 2 + 3 = 4
// 11: 1 + 2 + 3 + 4 + 5 = 15, 15 - 11 = 4, 4/2 = 2, 1 - 2 + 3 + 4 + 5 = 11

// 2: 1 + 2 = 3 > 2, 3 - 2 = 1 which is odd, we need an extra move: 1 + 2 + 3 = 6 - 2 = 4, 4/2 = 2, 1 - 2 + 3 = 2
// 5: 1 + 2 + 3 = 6, 6 - 5 = 1, 1 + 2 + 3 + 4 = 10, 10 - 5 = 5, 1 + 2 + 3 + 4 + 5 = 15, 15 - 5 = 10

class Solution4 {
public:
  int reachNumber(int target) {
    target = abs(target);
    int k = 0;
    int sum = 0;
    while (sum < target) {
      sum += ++k;
    }

    int delta = sum - target;
    if (delta % 2 == 0) return k;
    return k + 1 + k % 2;
  }
};

int main()
{
  Solution4 sol;
  cout << sol.reachNumber(3) << endl; // 2
  cout << sol.reachNumber(2) << endl; // 3
  cout << sol.reachNumber(-1000000000) << endl;
}
