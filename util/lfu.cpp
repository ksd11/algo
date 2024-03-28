#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int val;
  int freq;
  Node *prev, *next;
  void remove() {
    this->prev->next = this->next;
    this->next->prev = this->prev;
  }
  Node(int k, int v) : key(k),val(v) {
    freq = 1;
    prev = this;
    next = this;
  }
};

class LFUCache {
  vector<Node *> node_freq;
  unordered_map<int, Node *> hash;
  int c;

  void insert_node_freq(int freq, Node *node) {
    int n = freq - 1;
    if (n >= node_freq.size()) {
      node_freq.push_back(new Node(0,0));
    }
    node->next = node_freq[n]->next;
    node->prev = node_freq[n];
    node_freq[n]->next = node;
    node->next->prev = node;
  }

  int remove_node_freq() {
    int i = 0;
    while (i < node_freq.size()) {
      if (node_freq[i]->next != node_freq[i]) {
        break;
      }
      i++;
    }
    auto vitim = node_freq[i]->prev;
    vitim->remove();
    int res = vitim->key;
    delete vitim;
    return res;
  }

  void update(Node *node) {
    node->remove();
    node->freq += 1;
    insert_node_freq(node->freq, node);
  }

public:
  LFUCache(int capacity) { c = capacity; }

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
        int val = remove_node_freq();
        hash.erase(val);
      }
      hash[key] = node;
      insert_node_freq(1, node);
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
  // LFUCache lfu(2);
  // lfu.put(1, 1); // cache=[1,_], cnt(1)=1
  // lfu.put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1
  // cout << lfu.get(1) << endl;    // 返回 1
  //                // cache=[1,2], cnt(2)=1, cnt(1)=2
  // lfu.put(3, 3); // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
  //                // cache=[3,1], cnt(3)=1, cnt(1)=2
  // cout << lfu.get(2) << endl;    // 返回 -1（未找到）
  // cout << lfu.get(3) << endl;    // 返回 3
  //                // cache=[3,1], cnt(3)=2, cnt(1)=2
  // lfu.put(4, 4); // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
  //                // cache=[4,3], cnt(4)=1, cnt(3)=2
  // cout<<lfu.get(1)<<endl; // 返回 -1（未找到）
  // cout<<lfu.get(3)<<endl; // 返回 3
  //             // cache=[3,4], cnt(4)=1, cnt(3)=3
  // cout<<lfu.get(4)<<endl; // 返回 4

  LFUCache lfu(1);
  lfu.put(2, 1);
  cout << lfu.get(2) <<endl;
  lfu.put(3, 2);
  cout << lfu.get(2) <<endl;
  return 0;
}