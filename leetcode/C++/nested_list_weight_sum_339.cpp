#include "common.hpp"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

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
  int depthSumImp(const vector<NestedInteger>& nestedList, int depth) {
    int sum = 0;

    for (const auto& list : nestedList) {
      if (list.isInteger()) { // base case
        sum += depth * list.getInteger();
      } else { // recursion
        sum += depthSumImp(list.getList(), depth+1);
      }
    }

    return sum;
  }

public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int init_depth = 1;
    return depthSumImp(nestedList, init_depth);
  }
};

int main()
{
}
