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


// navie solution: store all values in a vector at initialization
class NestedIterator {
private:
  void flatten(const vector<NestedInteger> &nestedList) {
    for (auto& list : nestedList) {
      if (list.isInteger()) {
        flattenedList.push_back(list.getInteger());
      } else {
        flatten(list.getList());
      }
    }
  }

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    flatten(nestedList);
    curr_pos = 0;
    len = flattenedList.size();
  }

  int next() {
    if (hasNext()) {
      return flattenedList[curr_pos++];
    }
  }

  bool hasNext() {
    return curr_pos < len ? true : false;
  }

private:
  vector<int> flattenedList;
  int curr_pos;
  int len;
};

// better solution: DFS + stack.
// During initialization, push each NestedInteger in the given nestedList
// into the stack from right to left.

// Each call to hasNext would examine the top element from the stack, if it
// is an integer, simply return true, else pop up the top element, flatten it
// to the stack, keep doing this until we've got a value node at the top of the stack.

class NestedIterator2 {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    int len = nestedList.size();
    for (int i = len - 1; i >= 0; --i) {
      nodes.push(nestedList[i]);
    }
  }

  int next() {
    return nextValue;
  }

  bool hasNext() {
    while (!nodes.empty()) {
      auto curr_node = nodes.top();
      nodes.pop();
      if (curr_node.isInteger()) {
        nextValue = curr_node.getInteger();
        return true;
      }
      auto curr_list = curr_node.getList();
      int len = curr_list.size();
      for (int i = len - 1; i >= 0; --i) {
        nodes.push(curr_list[i]);
      }
    }
    return false;
  }

private:
  stack<NestedInteger> nodes;
  int nextValue;
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
}
