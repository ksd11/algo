#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int>fa;
map<pair<int,int>,bool>mp;
vector<vector<int>>b;

int find(int x){
    if(x==fa[x])return x;
    else return fa[x] = find(fa[x]);
}

void combine(int x, int y){
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
}

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    b.resize(q+1); // 保存所有查询
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        fa[x] = x, fa[y] = y;
        if(x>y)swap(x,y);
        mp.insert({{x,y},true});
    }
    for(int i=1; i<=q; i++){
        b[i].resize(3);
        cin>>b[i][0]>>b[i][1]>>b[i][2];
        if(b[i][1]>b[i][2])swap(b[i][1],b[i][2]);
        if(b[i][0]==1 && mp.count({b[i][1],b[i][2]}))mp[{b[i][1],b[i][2]}] = false;
    }
    for(auto &it:mp){
        auto [x,y] = it.first;
        if(it.second)combine(x, y);
    }
    stack<string>ans;
    for(int i=q; i>=1; i--){
        int fx = find(b[i][1]), fy = find(b[i][2]);
        if(b[i][0]==2){
            if(fx && fx==fy)ans.push("Yes");
            else ans.push("No");
        }else{
            if(mp.count({b[i][1],b[i][2]})) fa[fx] = fy;
        }
    }
    while(ans.size()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
    return 0;
}