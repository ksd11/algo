#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    stack<char> st;
    set<char> exist;
    map<char, int> char_cnt;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      char_cnt[s[i]]++;
    }

    for (int i = 0; i < n; i++) {
      if (exist.count(s[i]) == 0) {
        while (!st.empty() && st.top() >= s[i] && char_cnt[st.top()] > 0) {
          exist.erase(st.top());
          st.pop();
        }
        st.push(s[i]);
        exist.insert(s[i]);
      }
      char_cnt[s[i]]--;
    }

    string res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(){
    cout << Solution().removeDuplicateLetters("bcabc");
    // cout << Solution().removeDuplicateLetters("abacb");
    return 0;
}