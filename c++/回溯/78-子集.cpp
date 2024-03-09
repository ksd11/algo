#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        for(int i=0;i < 1<<size;i ++){
            vector<int> vec;
            for(int j=0;j<size;j++){
                if(1<<j & i){
                    vec.push_back(nums[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};