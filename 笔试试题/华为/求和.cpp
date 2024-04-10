#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 2) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;

    vector<vector<int>> dp(n, vector<int>(sum+1, 0)); // dp[i][j]表示前i个(前0个包括0)，和为j的个数

    if(arr[0] <= sum)
        dp[0][arr[0]] = 1;
    dp[0][0] = 1;

    for(int i=1;i<n;i++){
        for(int s=0;s<=sum;s++){
            if(s >= arr[i]){
                dp[i][s] = dp[i-1][s-arr[i]] + dp[i-1][s];
            }else{
                dp[i][s] = dp[i-1][s];
            }
        }
    }

    cout << dp[n-1][sum] << endl;

    return 0;
}