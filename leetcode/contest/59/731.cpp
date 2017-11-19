#include "../common.hpp"

class MyCalendarTwo {
public:
  MyCalendarTwo() {

  }

  bool book(int start, int end) {
    if (ends.empty()) {
      end2start[end] = start;
      ends.push_back(end);
      book2cnt[{start, end}] = 1;
      return true;
    }

    auto up = upper_bound(ends.begin(), ends.end(), end);
    if (up == ends.end()) {
      if (start < ends[ends.size() - 1]) {
        if (book2cnt[{end2start[ends[ends.size() - 1]], ends[ends.size() - 1]}] == 1) {
          end2start[end] = start;
          ends.push_back(end);
          book2cnt[{start, end}] = 1;
          book2cnt[{end2start[ends[ends.size() - 1]], ends[ends.size() - 1]}] = 2;
          return true;
        } else return false;
      }
      end2start[end] = start;
      ends.push_back(end);
      book2cnt[{start, end}] = 1;
      return true;
    }

    int rend = *up;
    if (end > end2start[rend]) {
      if (book2cnt[{end2start[rend], rend}] == 1) {
        end2start[end] = start;
        ends.push_back(end);
        sort(ends.begin(), ends.end());
        book2cnt[{start, end}] = 1;
        book2cnt[{end2start[rend], rend}] = 2;
        return true;
      }
      else return false;
    }
    --up;
    int lend = *up;
    if (start < lend) {
      if (book2cnt[{end2start[lend], lend}] == 1) {
        end2start[end] = start;
        ends.push_back(end);
        sort(ends.begin(), ends.end());
        book2cnt[{start, end}] = 1;
        book2cnt[{end2start[lend], lend}] = 2;
        return true;
      } else return false;
    }

    end2start[end] = start;
    ends.push_back(end);
    book2cnt[{start, end}] = 1;
    sort(ends.begin(), ends.end());
    return true;
  }

private:
  unordered_map<int, int> end2start;
  map<pair<int, int>, int> book2cnt;
  vector<int> ends;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
int main()
{
  MyCalendarTwo MyCalendar;
  cout << MyCalendar.book(10, 20) << endl; // returns true
  cout << MyCalendar.book(50, 60) << endl; // returns true
  cout << MyCalendar.book(10, 40) << endl; // returns true
  cout << MyCalendar.book(5, 15) << endl; // returns false
  cout << MyCalendar.book(5, 10) << endl; // returns true
  cout << MyCalendar.book(25, 55) << endl; // returns true
}
