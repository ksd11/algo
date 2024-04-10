
/*
最长子序列


dp[i][j] = dp[i-1][j-1]  if word1[i] == word2[j]
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) else

init:
if i == 0 or j == 0
dp[i][j] = 0

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int common = dp[n1][n2];
        return n1 - common + n2 - common;
    }
};

int main(){
    cout << Solution().minDistance("sea", "eat");
    return 0;
}