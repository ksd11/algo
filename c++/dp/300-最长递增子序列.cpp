#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(),1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(){
    // vector<int> vec = {4,10,4,3,8,9};
    vector<int> vec = {1,3,6,7,9,4,10,5,6};
    Solution().lengthOfLIS(vec);
    return 0;
}