#include<vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
       if(nums[i] > 0) return res;
       if(i>0 && nums[i] == nums[i-1]) continue;
       int L = i+1;
       int R = n-1;
       while(L<R){
        if(nums[L]+ nums[R]+nums[i] == 0){
            res.push_back({nums[i], nums[L], nums[R]});
            L++;
            R--;
            while(L<R && nums[L] == nums[L-1]) L++;
            while(L<R && nums[R] == nums[R+1]) R--;
        }else if(nums[L]+ nums[R]+nums[i] > 0){
            R--;
        }else{
            L++;
        }
       }
    }
    return res;
  }
};