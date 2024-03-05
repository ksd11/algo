#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i){
                if(nums[i] <= 0){
                    nums[i] = -1;
                }else{
                    int j = nums[i];
                    while(j > 0 && j<nums.size() && nums[j] != j){
                        int k = nums[j];
                        nums[j] = j;
                        j = k;
                    }
                }
            }
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i] != i){
                return i;
            }
        }

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==nums.size()){
        //         return nums.size()+1;
        //     }
        // }

        return nums.size();
    }
};


int main(){
    // vector<int> nums = {3,4,-1,1};
    // vector<int> nums = {4,2,1,43,7, 9};
    vector<int> nums = {1,2,6,3,5,4};
    cout<<Solution().firstMissingPositive(nums)<<endl;
    return 0;
}