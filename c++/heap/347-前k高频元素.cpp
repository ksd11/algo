#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
  template<typename T, typename Cmp>
  class Heap {
    public:
    void adjustHeap(vector<T> &nums, int k, int n) {
      // int n = nums.size();
      while (1) {
        int l = 2 * k + 1;
        int r = l + 1;
        int idx;
        if (l < n && r < n) {
          if (Cmp()(nums[r],nums[l])) {
            idx = l;
          } else {
            idx = r;
          }
        } else if (l < n) {
          idx = l;
        } else {
          return;
        }

        if (Cmp()(nums[k], nums[idx])) {
          swap(nums[idx], nums[k]);
          k = idx;
        } else {
          return;
        }
      }
    }

    void buildHeap(vector<T> &nums) {
      int k = (nums.size() - 2) / 2;
      while (k >= 0) {
        adjustHeap(nums, k, nums.size());
        k--;
      }
    }
  };

  // 小于比较器
  struct Comparator{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    }
  };

  public : vector<int>
           topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (auto &num : nums) {
      m[num] += 1;
    }

    vector<pair<int, int>> vec;
    for(auto &p : m){
        vec.push_back(p);
    }

    Heap<pair<int, int>, Comparator> heap;
    heap.buildHeap(vec);

    vector<int> res;
    int n = vec.size();
    for(int i=0;i<k;i++){
        res.push_back(vec[0].first);
        swap(vec[0], vec[n-1-i]);
        heap.adjustHeap(vec, 0, n-1-i);
    }
    return res;
  }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution().topKFrequent(nums, k);
    return 0;
}