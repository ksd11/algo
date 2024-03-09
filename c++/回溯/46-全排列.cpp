#include<vector>
#include <iostream>
using namespace std;


class Solution {
    vector<vector<int>> res;
    bool is_visited[10];
    int n;
    void dfs(int k, vector<int> &cur, vector<int> &nums){
        if(cur.size() == n){
            vector<int> vec;
            for(int i=0;i<n;i++){
                vec.push_back(nums[cur[i]]);
            }
            res.push_back(vec);
            return;
        }
        is_visited[k] = true;
        for(int i=0;i<n;i++){
            if(is_visited[i]) continue;
            cur.push_back(i);
            dfs(i, cur, nums);
            cur.pop_back();
        }
        is_visited[k] = false;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> cur;
        for(int i=0;i<n;i++){
            cur.push_back(i);
            dfs(i, cur, nums);
            cur.pop_back();
        }
        return res;
    }
};

int main(){
    vector<int> vec = {1,2,3};
    auto res = Solution().permute(vec);
    for(auto &row:res){
        for(auto& i:row){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}