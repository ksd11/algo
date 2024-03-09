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
 #include<vector>
 #include <algorithm>
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
  ListNode *sortList(ListNode *head) {
    vector<int> vec;
    ListNode* p = head;
    while(p){
        vec.push_back(p->val);
        p = p->next;
    }

    sort(vec.begin(), vec.end());

    int cnt = 0;
    p = head;
    while(p){
        p->val = vec[cnt++];
        p = p->next;
    }
    return head;
  }
};

#include <iostream>
int main(){
  ListNode l5(5);
  ListNode l4(4, &l5);
  ListNode l3(3, &l4);
  ListNode l2(2, &l3);
  ListNode l1(1, &l2);

//   ListNode l2(2, nullptr);
//   ListNode l1(1, &l2);

  ListNode* root = Solution().sortList(&l1);

  while(root){
    std::cout << root->val << endl;
    root = root -> next;
  }

  return 0;
}