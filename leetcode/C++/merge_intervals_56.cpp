#include "common.hpp"

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool IntervalCmp(Interval i1, Interval i2) {
  return i1.start < i2.start;
}

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    int len = intervals.size();
    if (!len) return ans;

    sort(intervals.begin(), intervals.end(), IntervalCmp);

    Interval cur = intervals[0];
    for (int i = 1; i < len; ++i) {
      if (cur.end >= intervals[i].start) {
        cur.end = max(intervals[i].end, cur.end);
      } else {
        ans.push_back(cur);
        cur = intervals[i];
      }
    }

    ans.push_back(cur);

    return ans;
  }
};

int main()
{
  vector<Interval> input {Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
  Solution sol;
  vector<Interval> output = sol.merge(input);
  for (auto& i : output) {
    cout << i.start << ',' << i.end << endl;
  }
}
