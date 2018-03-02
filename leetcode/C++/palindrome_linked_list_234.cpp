#include "common.hpp"


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


// use stack, extra space used

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    stack<int> tmp;
    ListNode* runner = head;
    while (runner) {
      tmp.push(runner->val);
      runner = runner->next;
    }

    runner = head;
    while (runner) {
      if (runner->val != tmp.top()) return false;
      tmp.pop();
      runner = runner->next;
    }

    return true;
  }
};


// O(n) time and O(1) space

class Solution2 {
public:
  bool isPalindrome(ListNode* head) {
    if (!head) return true;

    int count = 0;
    ListNode* runner = head;
    while (runner) {
      runner = runner->next;
      ++count;
    }

    int mid = count / 2 - 1;
    int i = 0;
    ListNode* midptr = head;
    while (i < mid) {
      midptr = midptr->next;
      ++i;
    }

    // reverse the first half of the linked list
    runner = head;
    while (runner != midptr) {
      ListNode* tmp = runner->next;
      runner->next = midptr->next;
      midptr->next = runner;
      runner = tmp;
    }

    ListNode* p1 = midptr;
    ListNode* p2 = head->next;
    if (count % 2 && p2) p2 = p2->next;
    while (p2) {
      if (p1->val != p2->val) return false;
      p1 = p1->next;
      p2 = p2->next;
    }

    return true;
  }
};


int main()
{
  Solution sol;
}
