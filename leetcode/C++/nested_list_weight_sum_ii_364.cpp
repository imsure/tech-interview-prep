#include "common.hpp"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

// idea: DFS. go through the list of NestedInteger one by one, keep track
// of the current depth d, if a NestedInteger n is an integer, then sum += n * d,
// if a NestedInteger is a list, then recursively calculate the sum with the same process
// with depth d + 1.

// time: O(N) where N is the number of nested elements in the input
// space: O(D) where D is the max depth of the nested list.
class Solution {
private:
  int _maxDepth(const NestedInteger& ni) {
    if (ni.isInteger()) return 1;
    else {
      return 1 + getMaxDepth(ni.getList());
    }
  }

  int getMaxDepth(const vector<NestedInteger>& nestedList) {
    int len = nestedList.size();
    int curr_depth;
    int max_depth = numeric_limits<int>::min();
    for (int i = 0; i < len; ++i) {
      curr_depth = _maxDepth(nestedList[i]);
      max_depth = max(max_depth, curr_depth);
    }

    return max_depth;
  }

  int depthSumImp(const vector<NestedInteger>& nestedList, int depth) {
    int sum = 0;

    for (const auto& list : nestedList) {
      if (list.isInteger()) { // base case
        sum += depth * list.getInteger();
      } else { // recursion
        sum += depthSumImp(list.getList(), depth-1);
      }
    }

    return sum;
  }

public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int max_depth = getMaxDepth(nestedList);
    return depthSumImp(nestedList, max_depth);
  }
};

// credit: https://discuss.leetcode.com/topic/49023/share-my-2ms-intuitive-one-pass-no-multiplication-solution

// idea: at each level, sum up all integer values to intsum, and construct all the nested list into a
// new nested list and pass the intsum along with newly constructed nestList to the next level of function call
// so that previous sums can be summed as many times as the depth level.

class Solution2 {
private:
  int _depthSum(vector<NestedInteger>& nestedList, int prev_sum) {
    int intsum = prev_sum;
    vector<NestedInteger> tmpList;
    for (const auto& list : nestedList) {
      if (list.isInteger()) {
        intsum += list.getInteger();
      } else {
        for (const auto& sublist : list.getList()) {
          tmpList.emplace_back(sublist);
        }
      }
    }

    int listsum = tmpList.empty() ? 0 : _depthSum(tmpList, intsum);
    return listsum + intsum;
  }

public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    return _depthSum(nestedList, 0);
  }
};

// thinking iteratively

class Solution3 {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int weighted = 0, unweighted = 0;
    while (!nestedList.empty()) {
      vector<NestedInteger> next_level;
      for (const auto& list : nestedList) {
        if (list.isInteger()) {
          unweighted += list.getInteger();
        } else {
          next_level.insert(next_level.end(), list.getList().begin(), list.getList().end());
        }
      }

      weighted += unweighted;
      nestedList = next_level;
    }

    return weighted;
  }
};

int main()
{
}
