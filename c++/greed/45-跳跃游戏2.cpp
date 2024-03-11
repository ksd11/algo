#include <vector>
using namespace std;

class Solution {
 public:
  // int jump(vector<int>& nums) {
  //     const int INF = 100000+5;
  //     int n = nums.size();
  //     vector<int> dis(n, INF);
  //     dis[n-1] = 0;
  //     for(int i=n-2; i>=0; i--){
  //         if(i+nums[i] >= n-1) dis[i]=1;
  //         else{
  //             for(int j=1;j<=nums[i];j++){
  //                 dis[i] = min(dis[i],dis[i+j] + 1);
  //             }
  //         }
  //     }
  //     return dis[0];
  // }
  int jump(vector<int>& nums) {
    int ans = 0;
    int end = 0;
    int maxPos = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      maxPos = max(nums[i] + i, maxPos);
      if (i == end) {
        end = maxPos;
        ans++;
      }
    }
    return ans;
  }
};

#include <iostream>
int main() {
  //   vector<int> nums = {2, 5, 0, 0};
    vector<int> nums = {2, 3, 1, 1,4};
    // vector<int> nums = {3,2,1,0,4};
//   vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  cout << Solution().jump(nums);
  return 0;
}