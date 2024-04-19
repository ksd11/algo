#include<bits/stdc++.h>
using namespace std;

/*
是3和5的倍数，但不是4的倍数
15的倍数，但不是60的倍数
dp15[i][j] 表示前i个元素，取余15余j的组合数

当不选择第i个元素时
dp15[i][j] += dp15[i-1][j]
选择第i个元素时
dp15[i][(j+arr[i])%15] += dp15[i-1][j]

*/

const int MOD=1e9+7;

int main(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp15(n, vector<int>(15, 0));
    vector<vector<int>> dp60(n, vector<int>(60, 0));
    dp15[0][0] = 1;
    dp15[0][arr[0]%15] = 1; // 有可能是负数

    dp60[0][0] = 1;
    dp60[0][arr[0]%60] = 1; // 有可能是负数

    for(int i=1;i<n;i++){
        for(int j=0;j<15;j++){
            dp15[i][j] += dp15[i-1][j];
            dp15[i][j] %= MOD;

            dp15[i][(j+arr[i])%15] += dp15[i-1][j];
            dp15[i][(j+arr[i])%15] %= MOD;
        }

        for(int j=0;j<60;j++){
            dp60[i][j] += dp60[i-1][j];
            dp60[i][j] %= MOD;

            dp60[i][(j+arr[i])%60] += dp60[i-1][j];
            dp60[i][(j+arr[i])%60] %= MOD;
        }
    }

    cout << dp15[n-1][0] - dp60[n-1][0] << endl;

    return 0;
}