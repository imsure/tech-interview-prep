#include "common.hpp"

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodeCmp {
  bool operator() (const ListNode* n1, const ListNode* n2) const {
    return n1->val > n2->val;
  }
};


// Utilize the already-implmented mergeTwoLists(l1, l2) to incrementally
// merge all the k lists into one sorted list.

// time: O(kn), mergeTwoLists takes O(n) and we need to do this by k times.
// space: O(1)

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

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (!n) return nullptr;
    if (n < 2) return lists[0];

    ListNode* cur_list = lists[0];
    for (int i = 1; i < n; ++i) {
      cur_list = mergeTwoLists(cur_list, lists[i]);
    }

    return cur_list;
  }
};


// Utilize a min heap to maintain current total k smallest elements from
// the k lists. Each time pop the top node from the heap and add it to the
// merged list and insert the next node (if any) of the popped node.
// Keep doing so until the heap is empty.

// e.g., when k = 3, and list1 = 1 -> 3 -> 7, list2 = 2 -> 4 -> 9, list3 = 5 -> 6 -> 8
// initially, the heap is:
//   1
//  / \
// 2   5
// pop up 1, so the merged list would be: 1->, and push 3 into the heap:
//   2
//  / \
// 3   5
// pop 2, merged list: 1->2, and push 4:
//   3
//  / \
// 4   5
// pop 3, merged list: 1->2->3, and push 7:
//   4
//  / \
// 7   5
// pop 4, merged list: 1->2->3->4, and push 9:
//   5
//  / \
// 7   9
// pop 5, merged list: 1->2->3->4->5, and push 6:
//   6
//  / \
// 7   9
// pop 6, merged list: 1->2->3->4->5->6, and push 8:
//   7
//  / \
// 8   9
// pop 7, merged list: 1->2->3->4->5->6->7, so further push since 7 is the last of list1
//   8
//  /
// 9
// pop 8, merged list: 1->2->3->4->5->6->7->8, so further push since 8 is the last of list3
// pop 9, merged list: 1->2->3->4->5->6->7->8->9, so further push since 9 is the last of list2
// now heap is empty, return.

// time: O(nlgk)
// space: O(k) taken by min heap

class Solution2 {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (!n) return nullptr;
    if (n < 2) return lists[0];

    priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> min_heap;
    for (int i = 0; i < n; ++i) {
      if (lists[i]) min_heap.push(lists[i]);
    }

    ListNode* cur_min_node, *prev_min_node, *head = nullptr;
    while (!min_heap.empty()) {
      cur_min_node = min_heap.top();
      min_heap.pop();
      if (!head) {
        head = cur_min_node;
        prev_min_node = head;
      } else {
        prev_min_node->next = cur_min_node;
        prev_min_node = cur_min_node;
      }
      if (cur_min_node->next) min_heap.push(cur_min_node->next);
    }

    return head;
  }
};

int main()
{
}
