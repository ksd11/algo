/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode res = ListNode(0, nullptr);
    ListNode *tmp = &res;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        tmp->next = list1;
        tmp = list1;
        list1 = list1->next;
      } else {
        tmp->next = list2;
        tmp = list2;
        list2 = list2->next;
      }
    }

    if (list1) {
      tmp->next = list1;
    } else {
      tmp->next = list2;
    }
    return res.next;
  }
};