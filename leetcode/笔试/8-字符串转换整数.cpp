#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        unsigned long long res = 0;
        bool sign_phase = true;
        bool skip_phase = true;
        int sign = 1;
        for(auto&c:s){
            // 前导0
            if(skip_phase && c==' ') continue;
            skip_phase = false;

            // 符号
            if(sign_phase && (c=='+' || c=='-')){
                sign_phase = false;
                sign = c == '-' ? -1 : 1;
                continue;
            } 
            sign_phase = false;

            if(c>='0' && c<='9'){
                res *= 10;
                res += c-'0';
                if(sign == 1 && res >= INT_MAX ){
                    return INT_MAX;
                }
                if(sign == -1 && res >= (long long)1 << 31){
                    return INT_MIN;
                }
            }else{
                break;
            }
        }
        return sign*res;
    }
};

int main(){
    cout << Solution().myAtoi("     -42");
    return 0;
}