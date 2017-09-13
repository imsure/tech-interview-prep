#include "common.hpp"

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };


// iterative solution

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    if (!p1) return p2;
    if (!p2) return p1;

    // new head points to the smallest node
    ListNode* head;
    if (p1->val < p2->val) {
      head = p1;
      p1 = p1->next;
    } else {
      head = p2;
      p2 = p2->next;
    }

    ListNode* p = head;
    while (p1 && p2) { // if we exhausted one list, stop
      // p should point to the next smallest node across two lists
      if (p1->val < p2->val) {
        p->next = p1;
        p1 = p1->next;
      } else {
        p->next = p2;
        p2 = p2->next;
      }
      p = p->next;
    }

    // just chain the rest to the tail
    if (p1) p->next = p1;
    else p->next = p2;

    return head;
  }
};


// recursive solution

class Solution2 {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* head;
    if (l1->val < l2->val) {
      head = l1;
      head->next = mergeTwoLists(l1->next, l2);
    } else {
      head = l2;
      head->next = mergeTwoLists(l1, l2->next);
    }

    return head;
  }
};

int main()
{
}
