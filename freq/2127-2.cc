#include<bits/stdc++.h>
using namespace std;

// 内向基环树

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> fav_number(n, 0);
        for(int i=0;i<n;i++){
            fav_number[favorite[i]]++;
        }

        // 找出所有入度为0的点
        queue<int> q;
        for(int i=0;i<n;i++){
            if(fav_number[i] == 0)
                q.push(i);
        }

        // 将环和树枝节点分开
        vector<int> max_chain(n, 1);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            fav_number[favorite[v]]--;
            max_chain[favorite[v]] = max(max_chain[favorite[v]], max_chain[v]+1);
            if(fav_number[favorite[v]]==0){
                q.push(favorite[v]);
            }
        }

        int max_chain_size = 0;
        int max_cycle_size = 0;
        for(int i=0;i<n;i++){
            if(fav_number[i] == 0) continue;

            // 求环大小
            fav_number[i] = 0;
            int k = favorite[i]; // 下一个位置
            int cnt = 1;
            while(k != i){
                fav_number[k] = 0;
                k = favorite[k];
                cnt ++;
            }

            // 找到环
            if(cnt == 2){
                max_chain_size +=  max_chain[i] + max_chain[favorite[i]];
            }else{
                max_cycle_size = max(max_cycle_size, cnt);
            }
        }

        return max(max_cycle_size, max_chain_size);
    }
};

int main(){
    // vector<int> favorite = {2,2,1,2};
    vector<int> favorite = {3,0,1,4,1};
    cout << Solution().maximumInvitations(favorite);
    return 0;
}