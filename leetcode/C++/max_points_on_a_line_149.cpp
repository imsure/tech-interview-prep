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

// Two points (x1, y1) and (x2, y2) form a line where slope = (y2-y1)/(x2-x1) = b/a
// Any point (xi, yi) is one this line iff (yi-y1)/(xi-x1) = bi/ai == b/a.

// For each point (x,y), we identify all the lines passing (x,y), and count the # of
// points on each line by using pair <b, a> as key, we must ensure GCD(b,a) == 1, note
// that a == 0 is a special case where all the points are on a vertical line. We also
// need to count the # of points that are the same with (x,y).

class Solution2 {
public:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  int maxPoints(vector<Point>& points) {
    int n = points.size();
    int max_global = 0;
    for (int i = 0; i < n; ++i) {
      Point pi = points[i];
      int max_local = 0; // max # of points on a line that is passing pi
      int same_points_cnt = 1;
      int verticals = 0;
      map<pair<int,int>, int> group_by_slope;
      for (int j = i + 1; j < n; ++j) {
        Point pj = points[j];
        if (pi.x == pj.x && pi.y == pj.y) ++same_points_cnt;
        else if (pi.x == pj.x) max_local = max(max_local, ++verticals);
        else {
          int b = pj.y - pi.y;
          int a = pj.x - pi.x;
          int g = gcd(a, b);
          b /= g;
          a /= g;
          max_local = max(max_local, ++group_by_slope[make_pair(b, a)]);
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
  Solution2 sol;
}
