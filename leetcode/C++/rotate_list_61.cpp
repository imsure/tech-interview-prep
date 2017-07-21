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

// cut the list at the (n-k)th elements, make the (n-k)th element
// the new tail and the (n-k+1)th element the new head,
// then connect the original tail to the original head.

class Solution2 {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (k <= 0 || !head || head->next == NULL) return head;

    int n = 0;
    ListNode* list_runner = head;
    while (list_runner) {
      ++n;
      list_runner = list_runner->next;
    }

    k = k % n;
    if (k == 0) return head;
    ListNode* head_orig = head; // backup
    list_runner = head;
    // move to the (n-k)th element
    for (int i = 1; i < n - k; ++i) {
      list_runner = list_runner->next;
    }

    ListNode* new_head;
    ListNode* list_runner2 = list_runner->next; // (n-k+1)th element
    new_head = list_runner2;
    list_runner->next = NULL; // new tail
    while (list_runner2->next) {
      list_runner2 = list_runner2->next;
    }

    list_runner2->next = head_orig;

    return new_head;
  }
};


// credit: https://discuss.leetcode.com/topic/14470/my-clean-c-code-quite-standard-find-tail-and-reconnect-the-list

// find tail and connect it with the head to form a cycle.
// then make the (n-k+1)th element the new head

class Solution3 {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (k <= 0 || !head || head->next == NULL) return head;

    int n = 1;
    ListNode* tail = head;
    while (tail->next) {
      ++n;
      tail = tail->next;
    }

    tail->next = head;

    k = k % n;
    if (k) {
      for (int i = 0; i < n - k; ++i) tail = tail->next; // move to the new tail
    }

    ListNode* new_head = tail->next;
    tail->next = NULL;
    return new_head;
  }
};

int main()
{
}
