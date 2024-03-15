#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(auto&c:s){
            if(!st.empty() && st.top() == c){
                st.pop();
            }
            else st.push(c);
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