#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
// 10^5以下预处理
int prime[maxn]; // 若是素数，得到-1，否则得到最小因子

void init_prime(int N){
    for(int i=2;i<=N;i++){
        if(prime[i]) continue;
        prime[i] = -1;
        for(int j=i+i;j<=N;j+=i){
            prime[j] = i;
        }
    }
}

int is_prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x % i == 0) return i; // i一定是素数
    }
    return -1;//表明是素数
}

bool isValid(int x){
    return sqrt(x) * sqrt(x) == x;
}

int main(){
    int x;
    cin >> x;
    int N = min(x, maxn-1);
    init_prime(N);
    int c;
    int res = 0;
    while(!isValid(x)){
        if(x<=N && prime[x] == -1 || (c = is_prime(x)) == -1){
            x -= 1;
        }else{
            x /= x < N ? prime[x] : c;
        }
        res++;
    }

    cout << res << endl; 

    return 0;
}