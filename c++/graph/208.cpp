#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
  bool exist = false;
  unordered_map<char, Node *> child;
  Node(bool e = false) { exist = e; }
};

class Trie {
  Node *_root;

public:
  Trie() { _root = new Node; }

  void insert(string word) {
    Node *node = _root;
    int cnt = 0;
    for (auto &c : word) {
      if (node->child.count(c)) {
        node = node->child[c];
        cnt++;
      } else {
        break; // node即为要插入的位置
      }
    }
    int size = word.size();
    for (int i = cnt; i < size - 1; i++) {
      node->child[word[i]] = new Node();
      node = node->child[word[i]];
    }
    if (cnt == size) {
      node->exist = true;
    } else {
      node->child[word[size - 1]] = new Node(true);
      node = node->child[word[size - 1]];
    }
  }

  bool search(string word) {
    Node *node = _root;
    for (auto &c : word) {
      if (node->child.count(c)) {
        node = node->child[c];
      } else {
        return false;
      }
    }
    return node->exist;
  }

  bool startsWith(string prefix) {
    Node *node = _root;
    for (auto &c : prefix) {
      if (node->child.count(c)) {
        node = node->child[c];
      } else {
        return false;
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */