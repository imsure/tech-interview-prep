#include "common.hpp"

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmpByStart(Interval v1, Interval v2)
{
  return v1.start < v2.start;
}

class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), cmpByStart);
    int len = intervals.size();
    for (int i = 0; i < len - 1; ++i) {
      if (intervals[i+1].start < intervals[i].end) {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  vector<Interval> intervals {Interval(5, 10), Interval(15, 20), Interval(0, 30)};
  Solution sol;
  cout << std::boolalpha << sol.canAttendMeetings(intervals) << endl;
  vector<Interval> intervals2 {Interval(5, 10), Interval(15, 20), Interval(0, 4)};
  cout << std::boolalpha << sol.canAttendMeetings(intervals2) << endl;
}
