#include<bits/stdc++.h>
using namespace std;


// count[SPLIT] -> 多0个1
// count[SPLIT] -> 多1个1
vector<int> mycount(400000+5, 0);

int main(){
    int SPLIT = 200000; //初始分界线位置
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    unsigned long long cnt1 = 0;
    unsigned long long cnt2 = 0;
    int left_half = 0;
    int right_half = 0;
    for(int i=0;i<n;i++){
        if(vec[i] == 2){ // split往左移动
            left_half -= mycount[SPLIT];
            mycount[SPLIT] += 1;
            right_half += mycount[SPLIT];
            SPLIT--;
        }else{
            mycount[SPLIT] += 1;
            SPLIT++;
            left_half += mycount[SPLIT]+1;
            right_half -= mycount[SPLIT];
        }

        cnt1 += left_half;
        cnt2 += right_half;
    }

    cout << cnt1 + cnt2*2<<endl;

    return 0;
}