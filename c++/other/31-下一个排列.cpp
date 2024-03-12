#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1; // idx和idx+1位置交换，然后idx+1到数组末尾对调
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx!=-1){
            int tmp = n-1;
            while(nums[tmp] <= nums[idx]) tmp--;
            swap(nums[idx], nums[tmp]);
        } 

        int i = idx+1;
        int j = n-1;
        while(i<j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};