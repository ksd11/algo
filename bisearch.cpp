
#include <vector>
using namespace std;

// 除非特殊说明，不然nums中的值都不重复，且nums是升序排列

// 在nums中查找target存不存在
int search(vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
  //   return l; // 则是返回插入的位置，第一个>target值的下标
}

// 如果lower=true, 找第一个>=target的index
// 如果lower=false, 找第一个>targer的index
// nums中元素的值可重复
int searchGreat(vector<int>& nums, int target, bool lower) {
  int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] > target || (lower && nums[mid] >= target)) {
      right = mid - 1;
      ans = mid;
    } else {
      left = mid + 1;
    }
  }
  return ans;
}

// 在nums中查找target的range，nums中的值可重复
vector<int> searchRange(vector<int>& nums, int target) {
  int leftIdx = searchGreat(nums, target, true);
  int rightIdx = searchGreat(nums, target, false) - 1;
  if (leftIdx <= rightIdx && rightIdx < nums.size() &&
      nums[leftIdx] == target && nums[rightIdx] == target) {
    return vector<int>{leftIdx, rightIdx};
  }
  return vector<int>{-1, -1};
}

// 旋转数组  1 2 3 4 5 -> 4 5 1 2 3
int searchRotate(vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  int res = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (nums[mid] == target) return mid;
    if (nums[mid] >= nums[l]) { // left
      if (nums[mid] > target && nums[l] <= target)
        r = mid - 1;
      else
        l = mid + 1;
    } else { // right
      if (nums[mid] < target && target <= nums[r])
        l = mid + 1;
      else
        r = mid - 1;
    }
  }
  return -1;
}

#include <iostream>
void print1D(vector<int> res) {
  for (auto& i : res) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  // vector<int> arr = {4,5,6,7,0,1,2};
  vector<int> arr = {1, 3};
  cout << searchRotate(arr, 3);
}