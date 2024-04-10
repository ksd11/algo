#include<bits/stdc++.h>
using namespace std;


/**
// lower_bound找到第一个不小于val的数
vector<int> vec = {1,2,5,6};
auto  pos = lower_bound(vec.begin(), vec.end(), 3);
cout << *pos << endl;
*/

// 计算从begin到end的和
int getRemain(vector<int> &tasks_sum, vector<int>::iterator begin){
    if(tasks_sum.begin() == begin) return *(tasks_sum.end()-1);
    return *(tasks_sum.end()-1)-*(begin-1);
}

int main(){
    int N,T;
    cin >> N >> T;
    vector<int> tasks_sum(N);
    cin >> tasks_sum[0];
    int max_task = tasks_sum[0];
    for(int i=1;i<N;i++){
        cin >> tasks_sum[i];
        if(max_task < tasks_sum[i]) max_task = tasks_sum[i];
        tasks_sum[i] += tasks_sum[i-1];
    }

    int min_res = (tasks_sum[N-1]+(T-1)) / T; // 至少要完成这么多任务才不会超过DDL
    int res = max(min_res, max_task);
    auto st = tasks_sum.begin();
    auto ed = tasks_sum.end();

    if(tasks_sum[N-1] <= res) {
        cout << res << endl;
        return 0;
    }

    int tmp = res;
    int remain;
    int t = T; // 还剩天数
    while(1){
        auto pos = lower_bound(st, ed, tmp);
        if(pos == ed) break;
        
        if(*pos == tmp){
            st = pos+1;
        }else{
            st = pos;
        }
        t--;
        tmp = *(st-1)+res; // 下一个能完成的任务总数

        remain = getRemain(tasks_sum, st);
        if(res * t < remain){ // 不够完成了
            res ++;
            tmp = res;
            st = tasks_sum.begin();
            t = T;
        }
    }
    cout << res << endl;
    return 0;
}