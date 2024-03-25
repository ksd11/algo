#include<bits/stdc++.h>
using namespace std;

/*
stamp = abca
target = aabcaca

提示一：从target出发反推
提示二：对于target每个下标，维护match, todo两个数组
       其中match指这个下标可以被stamp匹配，todo表示暂时无法被匹配
*/


class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.length();
        int n = target.length();
        map<int, pair<set<int>, set<int>>> match; 
        vector<bool> finish(target.size(), false);
        queue<int> q;
        vector<int> res;

        for(int i=0;i<n-m+1;i++){
            for(int j=0;j<m;j++){
                int a = target[i+j];
                if(a==stamp[j]){
                    match[i].first.insert(i+j);
                }else{
                    match[i].second.insert(i+j);
                }
            }

            if(match[i].second.empty()){
                res.push_back(i);
                // 添加
                for(int j=i;j<i+m;j++){
                    if(!finish[j]){
                        finish[j] = true;
                        q.push(j);
                    }
                }
            }
        }

        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int i=max(0,v-m+1); i<=v;i++){
                if(match[i].second.count(v)){
                    match[i].second.erase(v);
                    if(match[i].second.size() == 0 && match[i].first.size() > 0){
                        res.push_back(i);
                        for(auto j:match[i].first){
                            if(!finish[j]){
                                finish[j] = true;
                                q.push(j);
                            } 
                        }
                    }
                }
            }
        }

        bool all_true = true;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                all_true = false;
                break;
            }
        }

        reverse(res.begin(), res.end());
        return  all_true ? res : vector<int>();
    }
};

void print1D(vector<int> res) {
  for (auto &i : res) {
    cout << i << " ";
  }
  cout << endl;
}

int main(){
    print1D(Solution().movesToStamp("abca", "aabcaca"));
    return 0;
    
}