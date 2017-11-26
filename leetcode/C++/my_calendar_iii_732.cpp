#include "common.hpp"

// Brute force: store each K-overlap in an array and for a new interval update
// overlap for all possible K values.

// Resulted in TLE

class MyCalendarThree {
public:
  MyCalendarThree() {
    maxK = 0;
  }

  bool checkOverlap(vector<pair<int, int>>& book, int start, int end,
                    vector<pair<int, int>>& overlaps) {
    auto it = book.begin();
    while (it != book.end()) {
      auto b = *it;
      if (end <= b.first || start >= b.second) ++it;
      else {
        overlaps.push_back({max(start, b.first), min(end, b.second)});
        ++it;
      }
    }

    if (overlaps.size()) return true;
    return false;
  }

  int book(int start, int end) {
    if (books.size() == 0) { // first booking
      vector<pair<int, int>> book {{start, end}};
      books.push_back(book);
      maxK = 1;
      return maxK;
    }

    int k;
    for (k = books.size() - 1; k >= 0; --k) {
      auto& book = books[k];
      vector<pair<int, int>> overlaps;
      if (checkOverlap(book, start, end, overlaps)) { // overlap withs some K-overlap interval
        if (k + 1 >= books.size()) books.push_back(overlaps);
        else {
          for (int i = 0; i < overlaps.size(); ++i) books[k+1].push_back(overlaps[i]);
        }
        maxK = max(maxK, k + 2); // +2 coz index starts from 0
      }
    }

    books[0].push_back({start, end});
    return maxK;
  }

private:
  vector<vector<pair<int, int>>> books;
  int maxK;
};


class MyCalendarThree2 {
public:
  MyCalendarThree2() {
    maxK = 0;
  }

  bool checkOverlap(set<pair<int, int>>& book, int start, int end,
                    set<pair<int, int>>& overlaps) {
    auto it = book.begin();
    while (it != book.end()) {
      auto b = *it;
      if (end <= b.first || start >= b.second) ++it;
      else {
        overlaps.insert({max(start, b.first), min(end, b.second)});
        ++it;
      }
    }

    if (overlaps.size()) return true;
    return false;
  }

  int book(int start, int end) {
    if (books.size() == 0) { // first booking
      set<pair<int, int>> book;
      book.insert({start, end});
      books.push_back(book);
      maxK = 1;
      return maxK;
    }

    int k;
    for (k = books.size() - 1; k >= 0; --k) {
      auto& book = books[k];
      set<pair<int, int>> overlaps;
      if (checkOverlap(book, start, end, overlaps)) { // overlap withs some K-overlap interval
        if (k + 1 >= books.size()) books.push_back(overlaps);
        else {
          for (auto overlap : overlaps) books[k+1].insert(overlap);
        }
        maxK = max(maxK, k + 2); // +2 coz index starts from 0
      }
    }

    books[0].insert({start, end});
    return maxK;
  }

private:
  vector<set<pair<int, int>>> books;
  int maxK;
};


class MyCalendarThree3 {
public:
  MyCalendarThree3() {
    maxK = 0;
  }

  bool checkOverlap(set<pair<int, int>>& book, int start, int end,
                    set<pair<int, int>>& overlaps) {
    auto lo = book.upper_bound({start, end});

    set<pair<int, int>>::iterator prev_lo;
    if (lo != book.begin()) {
      prev_lo = --lo;
      ++lo;
    }

    if (lo == book.end() && start >= prev_lo->second) return false;
    if (lo == book.begin() && end <= lo->first) return false;
    if (lo != book.begin() && lo != book.end() && end <= lo->first && start >= prev_lo->second) return false;

    if (lo == book.end()) {
      while (prev_lo != book.begin() && start < prev_lo->second) {
        overlaps.insert({start, min(end, prev_lo->second)});
        --prev_lo;
      }
      if (prev_lo == book.begin() && start < prev_lo->second) overlaps.insert({start, min(end, prev_lo->second)});
    } else if (lo == book.begin()) {
      while (lo != book.end() && end > lo->first) {
        overlaps.insert({lo->first, min(end, lo->second)});
        ++lo;
      }
    } else { // lo is in the middle
      while (prev_lo != book.begin() && start < prev_lo->second) {
        overlaps.insert({start, min(end, prev_lo->second)});
        --prev_lo;
      }
      if (prev_lo == book.begin() && start < prev_lo->second) overlaps.insert({start, min(end, prev_lo->second)});

      while (lo != book.end() && end > lo->first) {
        overlaps.insert({lo->first, min(end, lo->second)});
        ++lo;
      }

      // if (start < prev_lo->second) overlaps.insert({start, min(end, prev_lo->second)});
      // if (end > lo->first) overlaps.insert({lo->first, min(end, lo->second)});
    }

    return true;
  }

  int book(int start, int end) {
    if (books.size() == 0) { // first booking
      set<pair<int, int>> book;
      book.insert({start, end});
      books.push_back(book);
      maxK = 1;
      return maxK;
    }

    int k, sz = books.size();
    for (k = sz - 1; k >= 0; --k) {
      auto& book = books[k];
      set<pair<int, int>> overlaps;
      if (checkOverlap(book, start, end, overlaps)) { // overlap withs some K-overlap interval
        if (k + 1 >= sz) books.push_back(overlaps);
        else {
          for (auto overlap : overlaps) books[k+1].insert(overlap);
        }
        maxK = max(maxK, k + 2); // +2 coz index starts from 0
      }
    }

    books[0].insert({start, end});
    // return maxK;
    return books.size();
  }

private:
  vector<set<pair<int, int>>> books;
  int maxK;
};


class MyCalendarThree4 {
public:
  MyCalendarThree4() {
    maxBooking = 0;
  }

  int book(int start, int end) {
    timeline[start]++;
    timeline[end]--;

    int booked = 0;
    for (auto kv : timeline) {
      booked += kv.second;
      maxBooking = max(maxBooking, booked);
    }

    return maxBooking;
  }

private:
  map<int, int> timeline;
  int maxBooking;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
int main()
{
  MyCalendarThree4 obj;
  cout << obj.book(10, 20) << endl; // 1
  cout << obj.book(50, 60) << endl; // 1
  cout << obj.book(10, 40) << endl; // 2
  cout << obj.book(5, 15) << endl;  // 3
  cout << obj.book(5, 10) << endl;  // 3
  cout << obj.book(25, 55) << endl; // 3
}
