#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct PairCompare {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first;
  }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, PairCompare> q;
    vector<int> res;

    for (int i = 0; i < k; i++) {
      q.push({nums[i], i});
    }
    res.push_back(q.top().first);
    for (int i = k; i < nums.size(); i++) {
      q.push({nums[i], i});
      while (q.top().second <= i - k) {
        q.pop();
      }
      res.push_back(q.top().first);
    }
    return res;
  }
};