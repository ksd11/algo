#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  void adjustHeap(vector<int> &nums, int k, int n) {
    // int n = nums.size();
    while (1) {
      int l = 2 * k + 1;
      int r = l + 1;
      int idx;
      if (l < n && r < n) {
        if (nums[l] > nums[r]) {
          idx = l;
        } else {
          idx = r;
        }
      } else if (l < n) {
        idx = l;
      } else {
        return;
      }

      if (nums[idx] > nums[k]) {
        swap(nums[idx], nums[k]);
        k = idx;
      } else {
        return;
      }
    }
  }

  void buildHeap(vector<int> &nums) {
    int k = (nums.size() - 2) / 2;
    while (k >= 0) {
      adjustHeap(nums, k, nums.size());
      k--;
    }
  }

 public:
  int findKthLargest(vector<int> &nums, int k) {
    buildHeap(nums);
    int n = nums.size();
    while(--k){
        swap(nums[0], nums[n-1]);
        adjustHeap(nums, 0, --n);
    }
    return nums[0];
  }
};