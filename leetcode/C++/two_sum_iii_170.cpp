#include "common.hpp"

// time:
// space:
// runtime: 135ms

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


// improved performance with two boundary checks
// runtime: 52ms

class TwoSum2 {
public:
  /** Initialize your data structure here. */
  TwoSum2() {
    min_val = numeric_limits<int>::max();
    max_val = numeric_limits<int>::min();
  }

  /** Add the number to an internal data structure.. */
  void add(int number) {
    ++num2count[number];
    min_val = min(min_val, number);
    max_val = max(max_val, number);
  }

  /** Find if there exists any pair of numbers which sum is equal to the value. */
  bool find(int value) {
    if (value < 2 * min_val || value > 2 * max_val) return false;

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
  int min_val;
  int max_val;
};


// runtime: 149ms
// unordered_multiset seems less efficient than unordered_map

class TwoSum3 {
public:
  /** Initialize your data structure here. */
  TwoSum3() {
  }

  /** Add the number to an internal data structure.. */
  void add(int number) {
    nums.insert(number);
  }

  /** Find if there exists any pair of numbers which sum is equal to the value. */
  bool find(int value) {
    for (const auto& n : nums) {
      int count = 2 * n == value ? 1 : 0;
      if (nums.count(value - n) > count) return true;
    }

    return false;
  }

private:
  unordered_multiset<int> nums;
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
