#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int qpow(int a,int b,int mod){
    long long res=1,t=a;
    while(b){
        if(b&1){
            res=1ll*(res*t)%mod;
        }
        b>>=1;
        t=(t*t)%mod;
    }
    return res;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> s(n + 1, q);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        s[x] -= 1;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res=(res+1ll*qpow(2, s[i + 1],mod)* a[i] % mod)%mod;
    }
    cout << res << endl;
    return 0;
}