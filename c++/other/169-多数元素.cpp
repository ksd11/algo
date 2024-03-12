#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int INF = 1e9+7;
        int cnt = 0;
        int ele = INF;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == ele || ele == INF){
                cnt++;
                ele = nums[i];
            }else{
                cnt--;
                if(cnt == 0) ele = INF;
            }
        }
        return ele;
    }
};

#include <iostream>
int main(){
    vector<int> nums = {6,5,5};
    cout << Solution().majorityElement(nums);
    return 0;
}