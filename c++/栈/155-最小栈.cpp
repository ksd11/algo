#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<pair<int, int>> q;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(q.empty()){
            q.push({val, val});
        }else{
            int min_val = q.top().second;
            q.push({val, min(min_val, val)});
        }
    }
    
    void pop() {
        q.pop();
    }
    
    int top() {
        return q.top().first;
    }
    
    int getMin() {
        return q.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */