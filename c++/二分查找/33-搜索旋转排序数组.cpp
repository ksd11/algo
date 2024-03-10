#include <iostream>
#include <vector>
using namespace std;

class Solution {

  bool check_r(vector<int> &nums, int k){
    if(k >=0)
      return nums[k] > nums[0];
    return false;
  }

  bool check_l(vector<int> &nums, int k){
    if(k<nums.size()){
      return nums[k] < nums[nums.size()-1];
    }
    return false;
  }
 public:
  int search(vector<int> &nums, int target) {
    int last_ele = nums[nums.size() - 1];
    int first_ele = nums[0];
    int split_right = 1;  // 右半边

    // 把一个的元素排除
    if (target == last_ele) return nums.size() - 1;
    if (target == first_ele) return 0;
    if (last_ele == first_ele) return -1;

    // 一定要在左半边找
    if (target > first_ele) split_right = 0;

    int l = 0, r = nums.size() - 1;
    bool normal = first_ele < last_ele; // 列表是否已经有序了

    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) return mid;

      if (nums[mid] > target) {
        if (!split_right || normal) {
          normal = true;
          r = mid - 1;
        } else {
          // split_right 并且 nums[mid] > target
          // if mid in left => l = mid + 1
          // else           => r = mid - 1

          if(nums[mid] >= first_ele){
            l = mid + 1;
            normal = check_l(nums, l);
          }else{
            r = mid - 1;
            normal = check_r(nums, r);
          }
        }
      } else {
        if (split_right || normal) {
          l = mid + 1;
          normal = true;
        } else {
          // split_left 并且 nums[mid] < target
          // if mid in left => l = mid + 1
          // else           => r = mid - 1
          if(nums[mid] >= first_ele){
            l = mid + 1;
            normal = check_l(nums, l);
          }else{
            r = mid - 1;
            normal = check_r(nums, r);
          }
        }
      }
    }

    return -1;
  }
};

int main() {
  vector<int> nums = {5, 1,2,3,4};
  // vector<int> nums = {5,7,7,8,8,10};
  cout << Solution().search(nums, 1);
  return 0;
}