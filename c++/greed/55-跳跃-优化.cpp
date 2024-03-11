#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int k = n - 1;
    while (k != 0) {
      int old_k = k;
      for (int i = k - 1; i >= 0; i--) {
        if (nums[i] > k - 1 - i) {
            k = i;
            break;
        }
      }

      if(old_k == k) return false;

      if(k==0) return true;
    }
    return true;
  }
};

#include <iostream>
int main() {
  vector<int> nums = {2, 5, 0, 0};
//   vector<int> nums = {2, 3, 1, 1,4};
//   vector<int> nums = {3,2,1,0,4};
  cout << Solution().canJump(nums);
  return 0;
}