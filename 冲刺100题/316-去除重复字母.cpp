#include<bits/stdc++.h>
using namespace std;

// bug version 贪心不行
class Solution {

    string getSmallBack(string s){
        vector<bool> delete_flag(s.length(), false);
        map<int, int> char_pos; // key: char  pos: 位置

        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(!char_pos.count(s[i])) char_pos[s[i]] = i;
            else{
                int next = i+1;
                while(delete_flag[next]) next++;
                if(s[i] < s[next]){
                    // 替换
                    int old = char_pos[s[i]];
                    delete_flag[old] = true;
                    char_pos[s[i]] = i;
                }else{
                    delete_flag[i] = true; // 删除是安全的，为什么？
                }
            }
        }

        string res;
        for(int i=0;i<n;i++){
            if(!delete_flag[i]){
                res.push_back(s[i]);
            }
        }
        return res;
    }

    string getSmallFront(string s){
        vector<bool> delete_flag(s.length(), false);
        map<int, int> char_pos; // key: char  pos: 位置

        int n = s.length();
        for(int i=0;i<n;i++){
            if(!char_pos.count(s[i])) char_pos[s[i]] = i;
            else{
                int next = i-1;
                while(delete_flag[next]) next--;
                if(s[i] > s[next]){
                    // 替换
                    int old = char_pos[s[i]];
                    delete_flag[old] = true;
                    char_pos[s[i]] = i;
                }else{
                    delete_flag[i] = true;
                }
            }
        }

        string res;
        for(int i=0;i<n;i++){
            if(!delete_flag[i]){
                res.push_back(s[i]);
            }
        }
        return res;
    }

public:
    string removeDuplicateLetters(string s) {
        // string rs = s;
        // reverse(s.begin(), s.end());
        return min(getSmallBack(s), getSmallFront(s));
    }
};

int main(){
    // cout << Solution().removeDuplicateLetters("bcabc");
    cout << Solution().removeDuplicateLetters("abacb");
    return 0;
}