#include "../common.hpp"

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
private:
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    int len = intervals.size();
    if (!len) return ans;

    sort(intervals.begin(), intervals.end(), IntervalCmp);

    Interval cur = intervals[0];
    for (int i = 1; i < len; ++i) {
      if (cur.end >= intervals[i].start-1) {
        cur.end = max(intervals[i].end, cur.end);
      } else {
        ans.push_back(cur);
        cur = intervals[i];
      }
    }

    ans.push_back(cur);

    return ans;
  }

public:
  string boldWords(vector<string>& words, string S) {
    vector<Interval> ins;
    for (auto& w : words) {
      size_t pos = S.find(w, 0);
      while (pos != string::npos) {
        ins.push_back(Interval(pos, pos+w.size()-1));
        pos = S.find(w, pos+1);
      }
    }

    auto intervals = merge(ins);

    int inc = 0;
    for (auto in : intervals) {
      // cout << in.start << ',' << in.end << endl;
      in.start += inc;
      S.insert(in.start, "<b>");
      inc += 3;
      in.end += inc;
      S.insert(in.end+1, "</b>");
      inc += 4;
    }

    return S;
  }
};


int main()
{
  vector<string> words {"bc", "ab"};
  Solution sol;
  cout << sol.boldWords(words, "aabcd") << endl;
  cout << sol.boldWords(words, "ababcdbc") << endl;
}
