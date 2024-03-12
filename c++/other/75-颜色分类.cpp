#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0};
        for(auto &num:nums) a[num]++;
        
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(a[k] > 0){
                nums[i] = k;
                a[k]--;
            }else{
                k++;
                i--;
            }
        }
    }
};