#include "common.hpp"


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


// Use extra space

class Solution {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> seen;
    ListNode *runner = head;
    while (runner) {
      if (seen.count(runner)) return true;
      seen.insert(runner);
      runner = runner->next;
    }

    return false;
  }
};


// No extra space used
// Use one slow pointer and one fast pointer, fast pointer
// runs twice faster than slow pointer. If there is a cycle,
// they will meet eventually.

class Solution2 {
public:
  bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;

    ListNode *slow = head;
    ListNode *fast = head->next->next;
    while (slow && fast) {
      if (slow == fast) return true;
      slow = slow->next;
      fast = fast->next;
      if (fast) fast = fast->next;
    }

    return false;
  }
};


int main()
{
  Solution sol;
}
