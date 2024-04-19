#include<bits/stdc++.h>
using namespace std;

// https://blog.csdn.net/m0_62097957/article/details/137795593

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    int odd_number = 0;
    int even_number = 0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] % 2) odd_number+=1;
        else even_number += 1;
    }

    int res = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2){
            res += odd_number-1;
            if(i>0 && arr[i-1] % 2) res--;
            if(i<n-1 && arr[i+1] % 2) res--;
        }else{
            res += even_number-1;
            if(i>0 && arr[i-1] % 2 == 0) res--;
            if(i<n-1 && arr[i+1] % 2 == 0) res--;
        }
    }

    cout << res/2 << endl;

    return 0;
}