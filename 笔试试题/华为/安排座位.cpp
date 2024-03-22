#include<bits/stdc++.h>
using namespace std;


// 占据座位
// 占据成功返回true，否则返回false
bool occupy(vector<int>& remain, int st, int ed){
    for(int i=st;i<ed;i++){
        if(remain[i] < 1) return false;
    }

    for(int i=st;i<ed;i++){
        remain[i] -= 1;
    }
    return true;
}

void release(vector<int>& remain, int st, int ed){
    for(int i=st;i<ed;i++){
        remain[i] += 1;
    }
}

// 获取某种分布的利用率
int utilization(vector<int>& remain, int total){
    for(auto &r:remain){
        total -= r;
    }
    return total;
}

int res = -1;
int total;

void dfs(int k, int x, vector<int> &remain, vector<pair<int, int>> &interval){
    if(k==x){
        res = max(res, utilization(remain, total));
        return;
    } 
    if(occupy(remain, interval[k].first, interval[k].second)){
        dfs(k+1, x, remain, interval);
        release(remain, interval[k].first, interval[k].second);
    }

    dfs(k+1, x, remain, interval);

}


int main(){
    int m,n,x;
    // 列车座位数，停靠站点数，预订人数
    cin >> m >> n >> x;
    vector<pair<int, int>> interval(x);
    for(int i=0;i<x;i++){
        int st, ed;
        cin >> st >> ed;
        interval[i] = {st, ed};
    }


    vector<int> remain(n, m);
    total = m*n;

    dfs(0, x, remain, interval);
    cout << res << endl;
    return 0;
}