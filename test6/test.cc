#include <bits/stdc++.h>
using namespace std;

class Cmp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)const {
        int a0 = min(a.first, a.second) ;
        int a1 = a.first + a.second - a0;
        int b0 = min(b.first, b.second) ;
        int b1 = b.first + b.second - b0;
        if (a0 != b0) return a0 < b0;
        if (a1 != b1) return a1 < b1;
        return false;
    }
};


map< pair<int, int>, int, Cmp> edge_count; // 边出现的次数
vector<int> path;
bool visited[1000 + 5];
int n, q;

bool dfs(int st, int ed, vector<vector<int>>& edges){
    visited[st] = true;
    path.push_back(st);
    if(st==ed){
        return true;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i] && edges[st][i] != 0){
            if(dfs(i, ed, edges)){
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}


void add_edges(int st, int ed, vector<vector<int>>& edges){
    memset(visited, 0, sizeof(visited));
    path.clear();
    dfs(st, ed, edges); // path保存了路径
    for(int i=1;i<path.size(); i++){
        int u = path[i-1];
        int v = path[i];
        edge_count[{u, v}]++;
    }
}

int main() {
    cin >> n >> q;
    vector<vector<int>> edges(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u][v] = w;
        edges[v][u] = w;
    }

    int st, ed;
    cin >> st; //出发位置
    for (int i = 0; i < q; i++) {
        cin >> ed;
        add_edges(st, ed,edges);
        st = ed;
    }

    int max_save = 0;
    int res = 0;
    for (auto& p : edge_count) {
        // cout << p.first.first << " " << p.first.second << " " << p.second << endl;

        int u = p.first.first;
        int v = p.first.second;
        if((edges[u][v]+1)/2 * p.second > max_save){
            max_save = (edges[u][v]+1)/2 * p.second;
        }
        res += edges[u][v] * p.second;
    }

    cout << res-max_save << endl;


}

/*
3 3
1 2 2
2 3 1
1 3 2 3

2
*/
// 64 位输出请用 printf("%lld")