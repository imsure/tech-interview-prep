#include "../common.hpp"

class MyCalendar {
public:
  MyCalendarTwo() {

  }

  bool book(int start, int end) {
    if (ends.empty()) {
      end2start[end] = start;
      ends.push_back(end);
      return true;
    }

    auto up = upper_bound(ends.begin(), ends.end(), end);
    if (up == ends.end()) {
      if (start < ends[ends.size() - 1]) {
        int lend2 = *(up - 1);
        if (start < lend2) return false;
      }

      end2start[end] = start;
      ends.push_back(end);
      return true;
    }

    int rend = *up;
    if (end > end2start[rend]) {
      int rend2 = *(up+1);
      if (end > end2start[rend2]) return false;
    }
    --up;
    int lend = *up;
    if (start < lend) {
      int lend2 = *(up - 1);
      if (start < lend2) return false;
    }

    end2start[end] = start;
    ends.push_back(end);
    sort(ends.begin(), ends.end());
    return true;
  }

private:
  unordered_map<int, int> end2start;
  vector<int> ends;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
int main()
{
  MyCalendar obj;
  cout << obj.book(10, 20) << endl;
  cout << obj.book(15, 25) << endl;
  cout << obj.book(20, 30) << endl;
}
