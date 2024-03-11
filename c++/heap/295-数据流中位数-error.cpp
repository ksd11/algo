
#include <vector>
using namespace std;

class MedianFinder {
  template <typename T, typename Cmp>
  class Heap {
   public:
    void adjustHeap(vector<T> &nums, int k, int n) {
      // int n = nums.size();
      while (1) {
        int l = 2 * k + 1;
        int r = l + 1;
        int idx;
        if (l < n && r < n) {
          if (Cmp()(nums[r], nums[l])) {
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
  struct Comparator {
    bool operator()(const int &a, const int &b) { return a < b; }
  };

  int _size = 0;
  Heap<int, Comparator> heap;
  vector<int> vec;

 public:
  MedianFinder() {}

  void addNum(int num) {
    vec.push_back(num);
    _size++;
    int k = (_size - 2) / 2;
    if (k >= 0) {
      heap.adjustHeap(vec, k, _size);
    }
  }

  double findMedian() {
    if (_size % 2 == 1) {
      return vec[_size / 2];
    } else {
      return double(vec[_size / 2] + vec[_size / 2 - 1]) / 2;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  MedianFinder medianFinder{};
  medianFinder.addNum(1);     // arr = [1]
  medianFinder.addNum(2);     // arr = [1, 2]
  medianFinder.findMedian();  // 返回 1.5 ((1 + 2) / 2)
  medianFinder.addNum(3);     // arr[1, 2, 3]
  medianFinder.findMedian();  // return 2.0
  return 0;
}