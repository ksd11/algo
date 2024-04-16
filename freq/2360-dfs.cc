#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<int> path;
    int res = -1;
    set<int> nodes;

    void dfs(int i, vector<int> &edges, vector<bool> &visit){
        if(visit[i]){
            // 找到环
            auto len = distance(find(path.begin(), path.end(), i), path.end());
            if(len == 0) return;
            res = max(res, int(len));
            return;
        }
        visit[i] = true;
        if(edges[i] == -1) return;
        
        path.push_back(i);
        dfs(edges[i], edges, visit);
        path.pop_back();
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> visit(edges.size(), false);
        for(int i=0;i<edges.size();i++){
            if(!visit[i]){
                dfs(i, edges, visit);
            }
        }
        return res;
    }
};

int main(){

    vector<int> vec = {\
    49,29,24,24,-1,-1,-1,2,23,-1,\
    44,47,52,49,9,31,40,34,-1,53,\
    33,-1,2,-1,18,31,0,9,47,35,\
    -1,-1,-1,-1,4,12,14,19,-1,4,\
    4,43,25,11,54,-1,25,39,17,-1,\
    22,44,-1,44,29,50,-1,-1};
    cout << Solution().longestCycle(vec);
    return 0;
}