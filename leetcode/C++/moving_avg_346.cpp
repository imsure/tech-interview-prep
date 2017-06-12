#include "common.hpp"

// time:
// space:
class MovingAverage {
private:
  queue<int> data {};
  int size;
  int prev_sum = 0;

public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    this->size = size;
  }

  double next(int val) {
    int sum;
    if (data.size() < size) {
      sum = prev_sum + val;
      prev_sum = sum;
      data.push(val);
      return (double)sum / (double)(data.size());
    } else {
      sum = prev_sum + val - data.front();
      prev_sum = sum;
      data.pop();
      data.push(val);
      return (double)sum / (double)size;
    }
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main()
{
  MovingAverage obj {3};
  double param = obj.next(1);
  cout << param << endl;
  param = obj.next(10);
  cout << param << endl;
  param = obj.next(3);
  cout << param << endl;
  param = obj.next(5);
  cout << param << endl;
}
