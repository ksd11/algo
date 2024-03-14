#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int L = j + 1;
        int R = n - 1;
        while (L < R && L < n && R < n) {
          if ((long long)(target) - nums[L] - nums[R] - nums[i] - nums[j] == 0) {
            res.push_back({nums[i], nums[j], nums[L], nums[R]});
            L++;
            R--;
            while (L < R && nums[L] == nums[L - 1]) L++;
            while (L < R && nums[R] == nums[R + 1]) R--;
          } else if ((long long)target - nums[L] - nums[R] - nums[i] - nums[j] < 0) {
            R--;
          } else {
            L++;
          }
        }
      }
    }
    return res;
  }
};

#include <iostream>
void print2D(vector<vector<int>> res) {
  for (auto &vec : res) {
    for (auto &i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main(){
    vector<int> vec = {2,2,2,2};
    // vector<int> vec ={0,0,0};
    print2D(Solution().fourSum(vec, 8));
    return 0;
}