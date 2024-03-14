struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* reverse(ListNode* head){
        while(!head) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        pre->next = nullptr;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode *res = nullptr;
        ListNode *cur = nullptr;
        ListNode *p;
        while(l1 && l2){
            p = l1;
            l1 = l1->next;
            p->next = l2;
            l2 = l2->next;
            if(cur){
                cur->next = p;
                cur = cur->next->next;
            } else{
                cur = p;
                cur = cur->next;
                res = cur;
            }
        }
        if(l1){
            cur->next = l1;
        }
        return res;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        forward(&fast, 2);
        forward(&slow, 1);
        if(!fast || !slow) return;
        while(1){
            forward(&fast, 2);
            if(!fast) break; 
            forward(&slow, 1);
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        l2 = reverse(l2);
        merge(l1, l2);
    }

    // 指针向前移动step格，若达到末尾，*p为nullptr
    void forward(ListNode** p, int step){
        while(*p && step--){
            *p = (*p)->next;
        }
        return;
    }
};


#include <iostream>
using namespace std;
int main(){
    // ListNode n5 = {5};
    // ListNode n4 = {4,&n5};
    ListNode n4 = {4,nullptr};
    ListNode n3 = {3, &n4};
    ListNode n2 = {2, &n3};
    ListNode n1 = {1, &n2};
    
    Solution().reorderList(&n1);
    ListNode* p = &n1;
    while(p){
        cout << p->val<<endl;
        p = p->next;
    }
    return 0;
}