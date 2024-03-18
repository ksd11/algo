#include <bits/stdc++.h>
using namespace std;

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

    // 反转，返回新链表头
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        pre->next = nullptr;
        while (cur) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

public:
  bool isPalindrome(ListNode *head) {
    int n = 0;
    ListNode* l1, *l2;
    l1 = head;
    while(l1){
        n++;
        l1 = l1->next;
    }

    // 找中间节点
    l2 = head;
    int k = n/2;
    while(k--) l2 = l2->next;
    l2 = reverse(l2);
    l1 = head;

    k = n / 2;
    while(k--){
        if((l1->val != l2->val)) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
  }
};

int main(){
    ListNode l4 = {1};
    ListNode l3 = {2, &l4};
    ListNode l2 = {2, &l3};
    ListNode l = {1,&l2 };
    cout << Solution().isPalindrome(&l);
    return 0;
}