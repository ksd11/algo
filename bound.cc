#include<bits/stdc++.h>
using namespace std;


// 返回>=val 的第一个位置
int lower_bound(vector<int> &arr, int val){
    int l = 0; 
    int r = arr.size()-1;
    while(l<=r){
        int mid = l + ((r-l)>>1);
        if(arr[mid] < val){
            l = mid+1; // 保证<l的位置，一定是<val的
        }else{
            r = mid-1;
        }
    }
    return l;
}

// 返回>val的第一个位置
int upper_bound(vector<int> &arr, int val){
    int l = 0; 
    int r = arr.size()-1;
    while(l<=r){
        int mid = l + ((r-l)>>1);
        if(arr[mid] <= val){
            l = mid+1; // 保证<l的位置，一定是<=val的
        }else{
            r = mid-1;
        }
    }
    return l;
}


int main(){
    vector<int> arr = {1,2,2,3,4,4,5};

    cout << lower_bound(arr, 2) << endl;
    cout << upper_bound(arr, 2) << endl;


    return 0;
}