// #include <cstdlib>
// #include <iostream>
// #include <stack>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> st;
    vector<int> vec(s.size(), -1);  // 配对位置
    // vec.at(-1);
    // int vec[30000+5];
    // memset(vec, -1, sizeof(vec));
    int cnt = 0;
    for (auto& c : s) {
      if (c == ')') {
        if (!st.empty()) {
          vec.at(st.top()) = cnt;  // 配对成功
          st.pop();
        }
      } else {
        st.push(cnt);
      }
      cnt++;
    }
    int res = 0;
    int cur = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == -1) continue;
      cur = vec[i] - i + 1;
      i = vec[i] + 1;
      while (i < vec.size() && vec[i] != -1) {
        cur += vec[i] - i + 1;
        i = vec[i] + 1;
      }
      res = max(res, cur);
    }
    return res;
  }
};

#include <iostream>
int main() {
  cout << Solution().longestValidParentheses(
      ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())");
  return 0;
}