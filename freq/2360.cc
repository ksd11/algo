#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> visited(edges.size(), false); // 有无遍历过
        int res = -1;

        for(int i=0;i<edges.size();i++){
            if(visited[i]) continue;

            vector<int> path;
            path.push_back(i);
            visited[i] = true;
            int next = edges[i]; // 下一个位置下标
            if(next < i) continue;

            while(next!=-1 && !visited[next]){
                visited[next] = true;
                path.push_back(next);
                next = edges[next];
            }
            // 环
            if(next!=-1 && edges[next]!=-1){
                int len = distance(find(path.begin(), path.end(), next), path.end());
                if(len == 0) continue;
                res = max(res, len);
            }
        }
        return res;
    }
};

int main(){

    vector<int> vec = {-1,4,-1,2,0,4};
    cout << Solution().longestCycle(vec);
    return 0;
}