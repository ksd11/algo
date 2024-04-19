#include<bits/stdc++.h>
using namespace std;

/*
思路分析：采用一个优先队列，每次取出一个最早开始的元素，看能不能执行，若能，这更新完成时间，若不能，wait更新
*/

int main(){
    int n,k;
    cin >> n >> k; // 蛋糕数，步骤
    typedef pair<int, int> Task;
    
    vector<int> workers(k), times(k), waiter(k); // 步骤k工作人员数，完成时间数，等待人员数
    
    for(int i=0;i<k;i++){
        cin >> workers[i] >> times[i];
    }

    priority_queue<Task, vector<Task>, greater<Task>> pq;
    for(int i=0;i<n;i++){
        pq.push({0,-1});
    }

    int ans = 0;
    while(!pq.empty()){
        auto task = pq.top();
        // cout << task.first <<" " << task.second << endl;
        pq.pop();
        ans = task.first; // 更新

        // waiter有人，则更新waiter
        if(task.second!=-1){
            if(waiter[task.second]>0){
                waiter[task.second]--;
                pq.push({task.first+times[task.second], task.second});
            }else{
                workers[task.second]++;
            }
        }

        // 更新执行时间
        if(task.second+1 < k){
            task.second++;
            if(workers[task.second] > 0){
                workers[task.second]--;
                task.first += times[task.second];
                pq.push(task);
            }else{
                waiter[task.second]++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}