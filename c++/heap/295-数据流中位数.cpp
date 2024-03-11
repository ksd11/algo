#include <queue>
using namespace std;

class MedianFinder {
 public:
  priority_queue<int, vector<int>, greater<int>> A;  // 大顶堆
  priority_queue<int, vector<int>, less<int>> B;     // 小顶堆

  MedianFinder() {}

  void addNum(int num) {
    if (A.size() != B.size()) {
      // 插入B
      A.push(num);
      B.push(A.top());
      A.pop();
    } else {
      // 插入A
      B.push(num);
      A.push(B.top());
      B.pop();
    }
  }

  double findMedian() {
    return A.size() == B.size() ? (A.top() + B.top()) / 2.0 : A.top();
  }
};