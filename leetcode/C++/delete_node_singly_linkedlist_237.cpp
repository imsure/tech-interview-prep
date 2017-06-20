#include "common.hpp"

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    if (node == NULL) return;
    if (node->next == NULL) return;

    ListNode* runner = node;
    while (runner && runner->next) {
      runner->val = runner->next->val;
      if (runner->next->next == NULL) {
        ListNode* tmp = runner->next;
        runner->next = NULL;
        free(tmp);
        break;
      }
      runner = runner->next;
    }
  }
};

int main()
{
}
