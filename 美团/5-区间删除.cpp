#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);

    vector<int> count2(n, 0);
    vector<int> count5(n,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
        while(arr[i] % 5 == 0){
            arr[i] /= 5;
            count5[i]++;
        }
        while(arr[i] % 2 == 0){
            arr[i] /= 2;
            count2[i]++;
        }
    } 
    long long res = 0;
    int cnt2 = 0;
    int cnt5 = 0;
    for(int i=0;i<n;i++){
        cnt2 += count2[i];
        cnt5 += count5[i];
    }

    if(cnt2 < k || cnt5 < k){
        cout<<0<<endl;
        return 0;
    } 

    int l = 0;
    for(int r=0;r<n;r++){
        cnt2-=count2[r];
        cnt5-=count5[r];
        while((cnt2<k||cnt5<k) && l<=r){
            cnt2+=count2[l];
            cnt5+=count5[l];
            l++;
        }
        if(l<=r) res += r-l+1;
    }


    cout<<res<<endl;
}
// 64 位输出请用 printf("%lld")


