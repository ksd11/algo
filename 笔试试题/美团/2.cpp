#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,q;
    cin >> n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int res = 0;
    int zero_cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0) res+=arr[i];
        else zero_cnt++;
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << res + l*zero_cnt <<" "<<res+r*zero_cnt<< endl;
    }
}
// 64 位输出请用 printf("%lld")