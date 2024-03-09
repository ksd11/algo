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

#include <queue>
using namespace std;

struct ListNode {

  int val;

  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare{
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.first > b.first;
    }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    int cnt = 0;
    for(auto &list : lists){
        if(list!=nullptr){
            q.push({list->val, cnt});
        }
        cnt++;
        
    }

    ListNode res = ListNode(0,nullptr);
    ListNode* p = &res;
    while(!q.empty()){
        auto ele = q.top();
        q.pop();

        p->next = new ListNode(ele.first);
        p = p->next;

        auto list = &lists[ele.second];
        *list = (*list)->next;
        if(*list != nullptr){
            q.push({(*list)->val, ele.second});
        }
    }

    return res.next;
  }
};