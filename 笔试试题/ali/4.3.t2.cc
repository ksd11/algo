#include<bits/stdc++.h>
using namespace std;
const int N=2E5+10;
int n,a[N];
long long f[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]; // 格子的分数

    vector<int>b={1,1};   //斐波拉切数列，最后一个数是大于n的
    for(int i=2;b.back()<=n;i++){
        b.push_back(b[i-1]+b[i-2]);
    }
    int m=b.size();
    memset(f,-0x3f,sizeof f); // 分数初始化

    f[1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<m;j++){
            int k=i-b[j];
            if(k<0)break;
            f[i]=max(f[i],f[k]+a[i]);
        }
    }
    cout<<f[n]<<endl;
    return 0;
}