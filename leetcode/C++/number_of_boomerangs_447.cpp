#include "common.hpp"


class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    unordered_map<int, unordered_map<int, int>> table;

    for (int i = 0; i < points.size(); ++i) {
      auto pi = points[i];
      for (int j = i+1; j < points.size(); ++j) {
        auto pj = points[j];
        int dist = pow(pi.first - pj.first, 2) + pow(pi.second - pj.second, 2);
        table[i][dist]++;
        table[j][dist]++;
      }
    }

    int ans = 0;
    for (int i = 0; i < points.size(); ++i) {
      auto& dist2count = table[i];
      for (auto& kv : dist2count) {
        int count = kv.second;
        if (count > 1) ans += count * (count - 1);
      }
    }

    return ans;
  }
};


int main()
{
  vector<pair<int, int>> points {{0,0}, {1,0}, {2,0}};
  Solution sol;
  cout << sol.numberOfBoomerangs(points) << endl;
}
