#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> nums;
    for (auto &s : tokens) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        int n2 = nums.top();
        nums.pop();
        int n1 = nums.top();
        nums.pop();
        switch (s[0]) {
        case '+':
          nums.push(n1 + n2);
          break;
        case '-':
          nums.push(n1 - n2);
          break;
        case '*':
          nums.push(n1 * n2);
          break;
        default:
          nums.push(n1 / n2);
        }
      }
      else{
        nums.push(atoi(s.c_str()));
      }
    }
    return nums.top();
  }
};

int main(){
    vector<string> ops = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution().evalRPN(ops);
    return 0;
}