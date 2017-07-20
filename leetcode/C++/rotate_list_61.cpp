#include "common.hpp"

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// for each node from (n-k+1)th node to the end of the list,
// remove it from the current postion and insert it at the
// correct position.

// need two pointers: one points to the node to be removed, one
// points to the position where we insert the removed node.

// note: the head here is the first element in the list, not the
// header that points to the first element (if exists)

// time: O(n)
// space: O(1)

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (k < 0) return head;
    if (!head) return head;

    int n = 0;
    ListNode* list_runner = head;
    while (list_runner) {
      ++n;
      list_runner = list_runner->next;
    }

    k = k % n; // round up k
    list_runner = head;
    int counter = 0;
    ListNode* ptr_remove;
    ListNode* ptr_prev = head;
    ListNode* ptr_insert = head; // insert the first removed node after head
    ListNode* next_node;
    while (list_runner) {
      ++counter;
      if (counter > n - k) {
        ptr_remove = list_runner;
        ptr_prev->next = ptr_remove->next;
        if (counter == n - k + 1) { // first insertion, insert before head, then changes the head
          ptr_remove->next = head;
          head = ptr_remove;
          ptr_insert = ptr_remove; // from now on, insert after ptr_insert
        } else {
          ptr_remove->next = ptr_insert->next;
          ptr_insert->next = ptr_remove;
          ptr_insert = ptr_remove; // insert the next removed node after previous removed node
        }
        // ptr_prev remains the same in case of removal
        list_runner = ptr_prev->next;
      } else {
        ptr_prev = list_runner;
        list_runner = list_runner->next;
      }
    }

    return head;
  }
};

int main()
{
}
