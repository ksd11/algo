#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        while(l!=r && nums[l] > nums[r]){
            int mid = (l+r)>>1;
            if(nums[l] <= nums[mid]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return nums[l];
    }
};