#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<bool> is_visited(n+1, false);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int res = 0;
    for(int i=1;i<=n;i++){
        if(is_visited[i]) continue;
        int k = i;
        int cnt = 0;
        while(!is_visited[k]){
            is_visited[k] = true;
            k = a[k];
            cnt++;
        }
        res += cnt*cnt;
    }
    cout << res << endl;
    return 0;
}