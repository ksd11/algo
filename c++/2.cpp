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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carrier = 0;
    ListNode res = ListNode(0, nullptr);
    ListNode *tmp = &res;
    while (l1 && l2) {
      l1->val += l2->val + carrier;
      carrier = (l1->val) / 10;
      l1->val %= 10;

      tmp->next = l1;
      tmp = tmp->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    if(!l1 && !l2 && carrier){
        tmp->next = new ListNode(1, nullptr);
        return res.next;
    }

    if(l2) l1 = l2;

    if (l1) {
      while (l1 && carrier) {
        l1->val += carrier;
        carrier = (l1->val) / 10;
        l1->val %= 10;

        tmp->next = l1;
        tmp = tmp->next;
        l1 = l1->next;
      }
      if(carrier){
        tmp->next = new ListNode(1, nullptr);
      }else{
        tmp->next = l1;
      }
    }

    return res.next;
  }
};