/*
0: 恒为0
1：第1次买入
2：第1次卖出
3：第2次买入
..
2k-1: 第k次买入
2k: 第k次卖出

dp[k] = max(dp[k], dp[k-1] - pow(-1,k)*prices[i]);

init:
dp[k] = -prices[0], k%2==1
else dp[k] = 0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp(2*k+1, 0);
        for(int i=1;i<2*k;i+=2){
            dp[i] = -prices[0];
        }
        for(int i=1;i<prices.size();i++){
            for(int j=1;j<=2*k;j++){
                dp[j] = max(dp[j], int(pow(-1, j))*prices[i]);
            }
        }
        return dp[2*k];
    }
};