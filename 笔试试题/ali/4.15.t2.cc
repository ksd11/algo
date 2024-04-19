#include<bits/stdc++.h>
using namespace std;

/*
dp[i][0] i点亮黄分数
dp[i][1] i点亮蓝分数
dp[i][2] i不点亮
*/
int main(){
    int n;
    cin >> n;

    vector<vector<int>> score(n, vector<int>(2, 0));
    for(int i=0;i<n;i++){
        cin >> score[i][0] >> score[i][1];
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = score[0][0];
    dp[0][1] = score[0][1];
    dp[0][2] = 0;

    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + score[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + score[i][1];
        dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    }

    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;


    return 0;
}