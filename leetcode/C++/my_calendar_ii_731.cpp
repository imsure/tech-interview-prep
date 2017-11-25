#include "common.hpp"

class MyCalendarTwo {
public:
  MyCalendarTwo() {

  }

  void insertDoubleBook(int start, int end) {
    if (doubleBooks.empty()) {
      doubleBooks.push_back({start, end});
      return;
    }

    // find the doubleBooksertion position if not double-booking
    auto it = doubleBooks.begin();
    while (it != doubleBooks.end()) {
      auto in = *it;
      if (end <= in.first) { // on the left of this interval, valid
        break;
      } else if (start >= in.second) { // on the right of this interval, advance
        ++it;
      } else { // invalid
        ++it; // shoulden't be here!
      }
    }

    doubleBooks.insert(it, {start, end});
  }

  bool book(int start, int end) {
    // look into double booked intervals to see if the current interval overlaps with any of them
    auto it = doubleBooks.begin();
    while (it != doubleBooks.end()) {
      auto book = *it;
      if (end <= book.first) break;
      else if (start >= book.second) ++it;
      else return false;
    }

    // if here, the current interval can be scheduled, then update double books if any
    for (it = books.begin(); it != books.end(); ++it) {
      auto book = *it;
      if (end > book.first && start < book.second) { // overlaps
        insertDoubleBook(max(start, book.first), min(end, book.second));
      }
    }
    books.push_back({start, end});
    return true;
  }

private:
  vector<pair<int, int>> books;
  vector<pair<int, int>> doubleBooks;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
int main()
{
  MyCalendarTwo obj;
  cout << obj.book(10, 20) << endl;
  cout << obj.book(50, 60) << endl;
  cout << obj.book(10, 40) << endl;
  cout << obj.book(5, 15) << endl;
  cout << obj.book(5, 10) << endl;
  cout << obj.book(25, 55) << endl;
}
