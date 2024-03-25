#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check_valid(vector<int>& tasks, vector<int>& workers, int k, int strength, int pill_number){
        // int n = task.size();
        auto task_pointer = tasks.end()-k;
        vector<int> valid(workers.size(), true); // 当前比较的任务
        int idx = workers.size()-1;

        while(task_pointer < tasks.end()){
            while(idx >= 0 && !valid[idx]) idx--;
            if(idx < 0) return false;
            if(workers[idx] >= *task_pointer){
                valid[idx] = false;
                idx--;
            }else{
                if(pill_number > 0 && *task_pointer - strength <= workers[idx] ){
                    // 查找吃药可以做此任务的位置
                    auto pos = lower_bound(workers.begin(), workers.end(), *task_pointer - strength);
                    int pos_int = int(pos-workers.begin());
                    while(pos_int <= idx && !valid[pos_int] ) pos_int++;
                    if(pos_int > idx) return false;
                    valid[pos_int] = false;
                    pill_number--;
                }else{
                    return false;
                }
            }
            task_pointer++;
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        // 任务倒序排序
        sort(tasks.begin(), tasks.end(), greater<int>());
        // worker正序排序
        sort(workers.begin(), workers.end());

        int l = 0;
        int r = tasks.size()-1;
        int res = 0;
        while(l<=r){
            int mid = (r+l)>>1;
            if(check_valid(tasks, workers, tasks.size()-mid, strength, pills)){
                res += r-mid+1;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};

int main(){
    vector<int> tasks = {5,4};
    vector<int> workers = {0,0,0};
    int pills = 1;
    int strength = 5;
    cout<<Solution().maxTaskAssign(tasks, workers, pills, strength);
    return 0;
}