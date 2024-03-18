#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> satify;
        map<char,int> char_pos; // 记录所有出现过的字符和位置
        set<int> no_satify; // 不满足要求的字符
        for(int i=0;i<s.length();i++){
            if(no_satify.count(s[i])) continue;
            else if(char_pos.count(s[i])){
                no_satify.insert(s[i]);
                char_pos.erase(s[i]);
            }else{
                char_pos[s[i]] = i;
            }
        }

        int min_val = -1;
        for(auto &p:char_pos){
            if(min_val == -1 || p.second < min_val){
                min_val = p.second;
            } 
        }
        return min_val;
    }
};

int main(){
    cout << Solution().firstUniqChar("leetcode");
    return 0;
    
}