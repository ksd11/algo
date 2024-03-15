#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(string& s, int n){
        int len = s.length();
        for(int i=0;i<n;i++){
            int k = n+i;
            while(k<len){
                if(s[k] != s[k-n]) return false;
                k += n;
            }
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len == 1) return false;
        for(int i=1;i<=len/2;i++){
            if(s[i] == s[0]){
                if(len%i == 0 && valid(s, i)) return true;     
            }
        }
        return false;
    }
};