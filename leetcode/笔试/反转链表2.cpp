struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 从head开始反转n个，返回头节点
    ListNode* reverse(ListNode* head, int n){
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(n-- && cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next = cur;
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int skip = left;
        ListNode* p = head;
        ListNode* pre = nullptr;
        while(--skip){
            pre = p;
            p = p->next;
        } 
        p = reverse(p, right-left);
        if(pre){
            pre->next = p;
            return head;
        } 
        return p;

    }
};

#include <iostream>
using namespace std;
int main(){
    ListNode n5 = {5};
    ListNode n4 = {4,&n5};
    ListNode n3 = {3, &n4};
    ListNode n2 = {2, &n3};
    ListNode n1 = {1, &n2};
    
    ListNode *p = Solution().reverseBetween(&n1, 2, 4);
    while(p){
        cout << p->val<<endl;
        p = p->next;
    }
    return 0;
}