/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

#include <map>

class Solution {
public:
  Node *copyRandomList(Node *head) {
    const int maxn = 1000 + 5;
    Node *address[maxn]; // 记录每个cnt的pointer address
    std::map<void *, int> mp;
    int cnt = 0;
    Node *res = NULL, *p1 = NULL, *p2 = NULL;
    p1 = head;

    while (p1) {
      Node *node = new Node(p1->val);
      mp.insert({p1, cnt});
      address[cnt++] = node;

      if (!res) {
        res = node;
        p2 = node;
      } else {
        p2->next = node;
        p2 = node;
      }
      p1 = p1->next;
    }

    p1 = head;
    p2 = res;
    while (p1) {
      if (p1->random) {
        int index = mp.at(p1->random);
        p2->random = address[index];
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    return res;
  }
};