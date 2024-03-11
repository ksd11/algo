#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int ele_num = sum / 2 + 1;
    vector<bool> m(ele_num, false);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = ele_num - nums[i] - 1; j >= 1; j--) {
        if (m[j]) {
          m[j + nums[i]] = true;
        }
      }
      if (nums[i] < ele_num) m[nums[i]] = true;

      if (m[ele_num - 1]) return true;
    }
    return m[ele_num - 1];
  }
};

#include <iostream>
int main() {
  // vector<int> vec = {2,2,3,5};
  vector<int> vec = {100};
  cout << Solution().canPartition(vec);
  return 0;
}