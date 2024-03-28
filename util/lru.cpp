#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int val;
  Node *prev, *next;
  void remove() {
    this->prev->next = this->next;
    this->next->prev = this->prev;
  }
  Node(int k, int v) : key(k), val(v) {
    prev = this;
    next = this;
  }
};

class LRUCache {
  Node *head; // 双链表头
  unordered_map<int, Node *> hash;
  int c;

  void insert_node(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next = node;
    node->next->prev = node;
  }

  int remove_node() {
    auto vitim = head->prev;
    vitim->remove();
    int res = vitim->key;
    delete vitim;
    return res;
  }

  void update(Node *node) {
    node->remove();
    insert_node(node); // 插到最前面
  }

public:
  LRUCache(int capacity) {
    c = capacity;
    head = new Node(0, 0);
  }

  int get(int key) {
    if (!hash.count(key)) {
      return -1;
    }
    Node *node = hash[key];
    update(node);
    return node->val;
  }

  void put(int key, int value) {
    Node *node;
    if (!hash.count(key)) {
      node = new Node(key, value);
      if (hash.size() >= c) {
        int val = remove_node();
        hash.erase(val);
      }
      hash[key] = node;
      insert_node(node);
    } else {
      node = hash[key];
      node->val = value;
      update(node);
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache lru(1);
  lru.put(2, 1);
  cout << lru.get(2) << endl;
  lru.put(3, 2);
  cout << lru.get(2) << endl;
  return 0;
}