#include "common.hpp"


// Brute force

// Time: O(N)
// Space: O(1)

// TODO: implement a DP solution


class Solution {
private:
  bool is_good_num(int n, vector<int>& map) {
    string str_n = to_string(n);
    string str_m;
    for (char d : str_n) {
      if (map[d - '0'] == -1) return false;
      str_m.push_back(map[d - '0'] + '0');
    }

    int m = stoi(str_m);
    if (m == n) return false;
    return true;
  }

public:
  int rotatedDigits(int N) {
    vector<int> map (10, -1);
    map[0] = 0;
    map[1] = 1;
    map[8] = 8;
    map[2] = 5;
    map[5] = 2;
    map[6] = 9;
    map[9] = 6;

    int ans = 0;
    for (int n = 1; n <= N; ++n) {
      if (is_good_num(n, map)) ++ans;
    }

    return ans;
  }
};


int main()
{
  Solution sol;
  cout << sol.rotatedDigits(10000) << endl;
}
