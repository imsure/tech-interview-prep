#include "common.hpp"

// Definition for a point.
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

// not ACed due to using double as key suffers from precision discretion problem.

class Solution {
public:
  int maxPoints(vector<Point>& points) {
    int n = points.size();
    int max_global = 0;
    for (int i = 0; i < n; ++i) {
      Point pi = points[i];
      int max_local = 0; // max # of points on a line that is passing pi
      int same_points_cnt = 1;
      unordered_map<double, int> group_by_slope;
      for (int j = i + 1; j < n; ++j) {
        // if (i == j) continue;
        Point pj = points[j];
        if (pi.x == pj.x && pi.y == pj.y) ++same_points_cnt;
        else if (pi.x == pj.x) max_local = max(max_local, ++group_by_slope[numeric_limits<double>::max()]);
        else {
          double slope = (double)(pj.y - pi.y) / (double)(pj.x - pi.x);
          max_local = max(max_local, ++group_by_slope[slope]);
        }
      }
      max_local += same_points_cnt;
      max_global = max(max_global, max_local);
    }

    return max_global;
  }
};

int main()
{
  Solution sol;
}
