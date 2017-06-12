#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// hash solution
// time: O(n), lookup time for unordered_map and unorded_set is constant in average.
// space: O(n)
class Solution {
public:
  bool isReflected(vector<pair<int, int> >& points) {
    if (points.empty()) {
      return true; // trivially true
    }

    unordered_map<int, unordered_set<int> > group_by_y; // y: <set of x values associated with y>
    int xmin {numeric_limits<int>::max()}, xmax{numeric_limits<int>::min()};

    // find min and max of x, if such an reflection line exists, it should
    // be at x = (xmin + xmax) / 2
    for (auto it = points.begin(); it != points.end(); it++) {
      xmin = min(xmin, it->first);
      xmax = max(xmax, it->first);
      group_by_y[it->second].emplace(it->first);
    }

    #if 1
    // make sure each point has a reflection point!
    for (const auto& p : points) {
      int xref = xmax + xmin - p.first;
      if (group_by_y[p.second].find(xref) == group_by_y[p.second].end()) {
        return false;
      }
    }
    #endif

    // will this be faster?
    int mid = xmax + xmin; // better to remove outside to avoid redundant computation
    for (const auto& keyval : group_by_y) {
      for (const auto& x : keyval.second) {
        if (keyval.second.count(mid - x) == 0) {
          return false;
        }
      }
    }

    return true;
  }
};

int main()
{
  pair<int, int> p1 (1, 1);
  pair<int, int> p2 (-1, 1);
  vector<pair<int ,int>> points {p1, p2};

  Solution sol;
  cout << sol.isReflected(points) << endl;
}
