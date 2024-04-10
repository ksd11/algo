#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m==0) return true;
        for(int i=n-1;i>=0;i--){
            if(t[i] == s[m-1]){
                return isSubsequence(s.substr(0, m-1), t.substr(0, i));
            }
        }
        return false;
    }
};

int main(){
    cout << Solution().isSubsequence("axc", "ahbgdc");
    return 0;
}