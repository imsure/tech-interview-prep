#include "../common.hpp"

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  int numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> set;
    for (int n : G) set.insert(n);

    int count = 0;
    bool in_comp = false;
    ListNode* runner = head;
    while (runner) {
      int v = runner->val;
      if (set.count(v)) {
        if (!in_comp) {
          count++;
          in_comp = true;
        }
        set.erase(v);
      } else {
        in_comp = false;
      }
      runner = runner->next;
    }

    return count;
  }
};


int main()
{
  Solution sol;
}
