#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> sim(N, vector<int>(N));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> sim[i][j];
        }
    }

    queue<int> no_visit;
    set<int> visit;
    for(int i=0;i<N;i++) no_visit.push(i); // 记录所有每分族的节点


    vector<int> res;
    while(true){

        // 找到一个还未分类的节点
        int v;
        int is_find = false;
        while(!no_visit.empty()){
            v = no_visit.front();
            no_visit.pop();
            if(!visit.count(v)){
                is_find = true;
                break;
            } 
        }
        if(!is_find) break;

        queue<int> q;
        int sim_res=0;
        q.push(v);
        visit.insert(v);

        while(!q.empty()){
            v = q.front();
            q.pop();
            for(int i=v+1; i< N; i++){
                if(sim[v][i] > 0){
                    sim_res += sim[v][i];
                    if(!visit.count(i)){
                        q.push(i);
                        visit.insert(i);
                    }
                }
            }
        }
        res.push_back(sim_res);
    }    

    sort(res.begin(), res.end(), greater<int>());

    cout << res[0];
    for(int i=1;i<res.size();i++){
        cout << " "<< res[i];
    }
    cout << endl;


    return 0;
}