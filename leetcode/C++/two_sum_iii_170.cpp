#include "common.hpp"

// time:
// space:

class TwoSum {
public:
  /** Initialize your data structure here. */
  TwoSum() {

  }

  /** Add the number to an internal data structure.. */
  void add(int number) {
    ++num2count[number];
  }

  /** Find if there exists any pair of numbers which sum is equal to the value. */
  bool find(int value) {
    int num, count;
    for (const auto& kv : num2count) {
      num = kv.first;
      count = kv.second;
      if (value == num * 2) {
        if (count > 1) return true;
        continue;
      }
      if (num2count.count(value - num)) return true;
    }

    return false;
  }

private:
  unordered_map<int, int> num2count;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

int main()
{
}
