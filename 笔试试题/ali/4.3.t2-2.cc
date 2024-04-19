#include<bits/stdc++.h>
using namespace std;

/*
dp[i] = dp[k]+a[i]

*/


int main(int argc,char *argv[]){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<int> f = {1,1};
    for(int i=2;f.back()<n;i++){
        f.push_back(f[i-1] + f[i-2]);
    }
    int fsize = f.size();

    vector<int> dp(n+1, -1e9-7);
    dp[1] = a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<fsize;j++){
            int k = i-f[j];
            if(k < 1) break;
            dp[i] = max(dp[i], dp[k]+a[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}