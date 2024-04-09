#include<bits/stdc++.h>
using namespace std;

class Solution {
    string str;
    int n;
    map<int, int> bracket; // bracket[i] = j 表示str中i下标为(，并且匹配位置j，j为)
    
    // 匹配括号
    void match(){
        stack<int> st;
        for(int i=0;i<n;i++){
            if(str[i] == '(') st.push(i);
            else if(str[i] == ')'){
                bracket[st.top()] = i;
                st.pop();
            }
        }
    }

    int readNumber(int& l, int& r){
        int res = 0;
        while(l <= r && str[l] >= '0' && str[l] <= '9'){
            res *= 10;
            res += str[l]-'0';
            l++;
        }
        return res;
    }

    void pop_and_calc(stack<int> &vals, char op){
        int rhs = vals.top();
        vals.pop();
        int lhs = vals.top();
        vals.pop();
        // op
        if(op=='+'){
            vals.push(lhs + rhs);
        }else{
            vals.push(lhs - rhs);
        }
    }

    int calc(int l, int r){
        stack<int> vals;
        stack<int> ops;
        int sign = 1;
        while(l<=r){
            if(isdigit(str[l])){
                int val = readNumber(l, r);
                vals.push(val*sign);
                sign = 1;
            }else if(str[l] == '('){
                int match_pos = bracket[l];
                int val = calc(l+1, match_pos-1);
                l = match_pos+1;
                vals.push(val*sign);
                sign = 1;
            }else if(str[l] == '+' || str[l] == '-'){
                char op = str[l++];
                if(!ops.empty()){
                    int cur_op = ops.top();
                    ops.pop();
                    pop_and_calc(vals, cur_op);
                }else if(op == '-' && vals.empty()){
                    sign = -1;
                    continue;
                }
                ops.push(op);
            }else{
                l++;
            }
        }
        if(!ops.empty()) pop_and_calc(vals, ops.top());
        return vals.top();
    }

public:
    int calculate(string s) {
        str = s;
        n = s.length();
        match();
        return calc(0, n-1);
    }
};

int main(){
    cout << Solution().calculate("2+2-1-2");
    return 0;
}