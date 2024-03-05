
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        // 计算前缀乘积
        int left = 1;
        for(int i=0;i<n;i++){
            res[i] *= left;
            left *= nums[i];
        }

        // 计算后缀乘积
        int right = 1;
        for(int i=n-1;i>=0;i--){
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};