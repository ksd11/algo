#include <queue>
#include <iostream>
using namespace std;
class MyStack {
  queue<int> q1;
  queue<int> q2;

  // exchange 并返回最后一个元素
  int exchange(bool pop) {
    if (!q1.empty()) {
      queue<int> tmp;
      tmp = q1;
      q1 = q2;
      q2 = tmp;
    }
    while (q2.size() > 1) {
      q1.push(q2.front());
      q2.pop();
    }
    int res = q2.front();
    q2.pop();
    if (!pop)
      q1.push(res);
    return res;
  }

public:
  MyStack() {}

  void push(int x) { q1.push(x); }

  int pop() {
    return exchange(true);
  }

  int top() {
    return exchange(false);
  }

  bool empty() { return q1.empty() && q2.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 int  main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    while(!obj->empty()){
        cout << obj->top() << endl;
        obj->pop();
    }
    return 0;
 }