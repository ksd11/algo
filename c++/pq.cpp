#include<iostream>
#include <queue>
#include <vector>
using namespace std;

struct PairCompare {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first;
  }
};

int main(int argc,char *argv[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, PairCompare> q;

    q.push({1, 2});
    q.push({4, 2});
    q.push({2, 3});

    while (!q.empty()) {
      auto top = q.top();
      q.pop();
      // 使用top元素
      cout << top.first << "->" << top.second << endl;
    }
    return 0;
}