#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
       string str;
       vector<string> res;
       while(ss >> str){
            // reverse(str.begin(), str.end());
            res.push_back(str);
       }

       string res_str;
       int first = true;
       for(int i=res.size()-1;i>=0;i--){
        if(!first) res_str+=" ";
        first = false;
        res_str += res[i];
       }
       return res_str;
    }
};