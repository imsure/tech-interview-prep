#include "common.hpp"

class MyCalendar {
public:
  MyCalendar() {

  }

  bool book(int start, int end) {
    if (ends.empty()) {
      end2start[end] = start;
      ends.push_back(end);
      return true;
    }

    auto up = upper_bound(ends.begin(), ends.end(), end);
    if (up == ends.end()) {
      if (start < ends[ends.size() - 1]) return false;
      end2start[end] = start;
      ends.push_back(end);
      return true;
    }

    int rend = *up;
    if (end > end2start[rend]) return false;
    --up;
    int lend = *up;
    if (start < lend) return false;

    end2start[end] = start;
    ends.push_back(end);
    sort(ends.begin(), ends.end());
    return true;
  }

private:
  unordered_map<int, int> end2start;
  vector<int> ends;
};


// sort the intervals with insertion sort

class MyCalendar2 {
public:
  MyCalendar2() {

  }

  bool book(int start, int end) {
    if (ins.empty()) {
      ins.push_back({start, end});
      return true;
    }

    // find the insertion position if not double-booking
    auto it = ins.begin();
    while (it != ins.end()) {
      auto in = *it;
      if ((end > in.first && end <= in.second) || (start >= in.first && start < in.second)
          || (start <= in.first && end >= in.second)) { // overlaps with this interval
        return false;
      }

      if (end <= in.first) { // on the left of this interval, valid
        break;
      }

      ++it;
    }

    ins.insert(it, {start, end});
    return true;
  }

private:
  vector<pair<int, int>> ins;
};


// same as above, but with simplified logic

class MyCalendar3 {
public:
  MyCalendar3() {

  }

  bool book(int start, int end) {
    if (ins.empty()) {
      ins.push_back({start, end});
      return true;
    }

    // find the insertion position if not double-booking
    auto it = ins.begin();
    while (it != ins.end()) {
      auto in = *it;
      if (end <= in.first) { // on the left of this interval, valid
        break;
      } else if (start >= in.second) { // on the right of this interval, advance
        ++it;
      } else { // invalid
        return false;
      }
    }

    ins.insert(it, {start, end});
    return true;
  }

private:
  vector<pair<int, int>> ins;
};


// use std::map

class MyCalendar4 {
public:
  MyCalendar4() {

  }

  bool book(int start, int end) {
    auto up = start2end.upper_bound(start); // first key > start
    if (up != start2end.end() && up->first < end) return false; // an existing book (on the right) overlaps with current one
    if (up != start2end.begin() && (--up)->second > start) return false; // an existing book (on the left) overlaps with current one

    start2end[start] = end;
    return true;
  }

private:
  map<int, int> start2end;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
int main()
{
  MyCalendar4 obj;
  cout << obj.book(10, 20) << endl;
  cout << obj.book(15, 25) << endl;
  cout << obj.book(20, 30) << endl;
}
