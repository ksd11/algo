/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    if (!head) {
      return false;
    }
    do {
      if (!forward(&slow)) {
        break;
      }
      if (!forward(&fast) || !forward(&fast)) {
        break;
      }

    } while (slow != fast);
    return slow != nullptr && slow == fast;
  }

  bool forward(ListNode **node) {
    if (!(*node)) {
      return false;
    }
    *node = (*node)->next;
    return true;
  }
};
