#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long total = 0;
    long long a,b;
    cin >> n;
    for(int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        total += tmp;
    }

    cin >> a >> b;

    cout << total - a-b <<endl;

    return 0;
}