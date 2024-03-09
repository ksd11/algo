#include <iostream>
#include <unordered_map>
using namespace std;

class LRUNode {
public:
  LRUNode *prev;
  LRUNode *next;
  int key;
  int value;
  LRUNode(int _key, int _value, LRUNode *_prev = nullptr,
          LRUNode *_next = nullptr) {
    key = _key;
    value = _value;
    prev = _prev;
    next = _next;
  }
};

class LRUCache {
public:
  LRUCache(int capacity) : _capactity(capacity){
    // _capactity = capacity;
    // hash.clear();

    // 头结点
    auto node = new LRUNode(0, 0);
    node->prev = node->next = node;
    _head = node;
  }

  int get(int key) {
    if (hash.count(key) == 0) {
      return -1;
    }
    auto node = hash.at(key);
    update(node);
    return node->value;
  }

  void put(int key, int value) {
    if (hash.count(key) == 0) {
      // 未找到直接插入
      if (_capactity <= 0) {
        // 驱逐
        auto victim = _head->prev;
        _head->prev = victim->prev;
        victim->prev->next = _head;

        hash.erase(victim->key);
        delete victim;
        _capactity++;
      }

      _capactity--;
      auto node = new LRUNode(key, value);
      hash.insert({key, node});
      insert_head(node);

    } else {
      auto node = hash.at(key);
      node->value = value;
      update(node);
    }
  }

  ~LRUCache() {
    auto node = _head->next;
    while (node != _head) {
      auto tmp = node;
      node = node->next;
      delete tmp;
    }
    delete _head;
  }

  void print() {
    auto node = _head->next;
    while (_head != node) {
      cout << node->value << " ";
      node = node->next;
    }
    cout << endl;
  }

private:
  int _capactity;
  unordered_map<int, LRUNode *> hash;
  LRUNode *_head;

  void insert_head(LRUNode *node) {
    node->next = _head->next;
    node->prev = _head;
    _head->next->prev = node;
    _head->next = node;
  }

  void update(LRUNode *node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
    insert_head(node);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

  LRUCache lRUCache = LRUCache(2);
  lRUCache.put(1, 1); // 缓存是 {1=1}

  lRUCache.print();

  lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
  lRUCache.print();
  lRUCache.get(1); // 返回 1
  lRUCache.print();
  lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}

  lRUCache.print();
  cout << lRUCache.get(2); // 返回 -1 (未找到)

  lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  lRUCache.print();
  lRUCache.get(1); // 返回 -1 (未找到)
  lRUCache.get(3); // 返回 3
  lRUCache.get(4); // 返回 4
}