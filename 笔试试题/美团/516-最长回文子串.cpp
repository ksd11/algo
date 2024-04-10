#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // is_recur表示i-j范围内的最大回文长度
        vector<vector<int>> is_recur(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            is_recur[i][i] = 1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j]){
                    is_recur[i][j] = max(is_recur[i][j], is_recur[i+1][j-1]+2);
                }else{
                    is_recur[i][j] = max(is_recur[i][j-1], is_recur[i+1][j]);
                }
            }
        }
        return is_recur[0][n-1];
    }
};


int main(){
    cout << Solution().longestPalindromeSubseq("bbbab");
    return 0;
}