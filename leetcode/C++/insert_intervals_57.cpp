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

  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ans;
    int len = intervals.size();
    if (!len) { ans.push_back(newInterval); return ans;}

    // binary search to find the point to insert the new interval
    int lo = 0, hi = len - 1, mid;
    bool need_insert = true;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (intervals[mid].start < newInterval.start) lo = mid + 1;
      else if (intervals[mid].start > newInterval.start) hi = mid - 1;
      else {
        intervals[mid].end = max(intervals[mid].end, newInterval.end);
        need_insert = false;
        break;
      }
    }

    // insert new interval before lo
    if (need_insert)
      intervals.insert(intervals.begin() + lo, newInterval);

    return merge(intervals);
  }
};


// more concise solution without doing binary search

class Solution2 {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ans;
    int len = intervals.size();
    int i = 0;

    // push each interval whose end is less newInterval's start
    while (i < len && intervals[i].end < newInterval.start) {
      ans.push_back(intervals[i++]);
    }

    // merge intervals that overlap with newInterval
    // overlapping boundary senarios:
    //        |----|
    //    |---|    |----|
    while (i < len && intervals[i].end >= newInterval.start && intervals[i].start <= newInterval.end) {
      newInterval.start = min(newInterval.start, intervals[i].start);
      newInterval.end = max(newInterval.end, intervals[i].end);
      ++i;
    }
    ans.push_back(newInterval);

    while (i < len) {
      ans.push_back(intervals[i++]);
    }

    return ans;
  }
};

int main()
{
  vector<Interval> input {Interval(1,3), Interval(6,9)};
  Solution2 sol;
  vector<Interval> output = sol.insert(input, Interval(7,10));
  for (auto& i : output) {
    cout << i.start << ',' << i.end << endl;
  }
}
