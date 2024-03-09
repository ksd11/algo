#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *st = head, *p = head, *ed;
    int cnt;
    ListNode* res;
    bool first = true;

    while (p) {
      cnt = 1;
      while (p && cnt < k) {
        p = p->next;
        cnt++;
      }
      if(!p){
        if(ed){
          ed -> next = st;
        }
        break;
      }

      p = p->next;
      auto pos = reverse(st, k);
      st = p;
      // pos.second->next = ?;
      if(first){
        head = pos.first;
        first = false;
      }else{
        ed -> next = pos.first;
      }
      ed = pos.second;
      ed->next = nullptr;
    }
    return head;
  }

  // 翻转链表，返回最前和最后元素的指针
  std::pair<ListNode *, ListNode *> reverse(ListNode *head, int k) {
    ListNode *prev = head;
    ListNode *cur = head->next;
    while (--k) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return {prev, head};
  }
};

int main(){
  /* ListNode l5(5);
  ListNode l4(4, &l5);
  ListNode l3(3, &l4);
  ListNode l2(2, &l3);
  ListNode l1(1, &l2); */

  ListNode l2(2, nullptr);
  ListNode l1(1, &l2);

  ListNode* root = Solution().reverseKGroup(&l1, 2);

  while(root){
    std::cout << root->val << endl;
    root = root -> next;
  }

  return 0;
}
