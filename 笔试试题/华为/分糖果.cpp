
#include<bits/stdc++.h>
using namespace std;

int get(vector<int> &arr, int flag){
    int res = 0;
    int cnt = 0;
    for(int i=1;i<=flag;i<<=1){
        if(i & flag){
            res ^= arr[cnt];
        }
        cnt++;
    }
    return res;
}

int getRes(vector<int> &arr, int flag){
    int res = 0;
    int cnt = 0;
    for(int i=1;i<=flag;i<<=1){
        if(i & flag){
            res += arr[cnt];
        }
        cnt++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    sort(arr.begin(), arr.end());
    int res=0;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        res ^= arr[i];
        sum += arr[i];
    }

    for(int i=1;i<(1<<n);i++){
        int v = get(arr, i);
        if((res ^ v) == v){
            cout << sum - getRes(arr, i) << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}