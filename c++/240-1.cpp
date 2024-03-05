#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
  // 返回ele所在的index
  pair<bool, int> bi_search(vector<int> &vec, int ele) {
    int l = 0;
    int r = vec.size() - 1;
    int m = -1;
    while (l <= r) {
      m = (l + r) >> 1;
      if (ele == vec[m]) {
        return {true, m};
      } else if (ele > vec[m]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return {false, m};
  }

  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l = 0, r = matrix[0].size();
    int u = 0, d = matrix.size();
    vector<int> vec;
    pair<bool, int> res;
    int pos;
    while(r-l >= 1 && d-u >= 1){
        
        // 上
        vec.clear();
        for(int i=l;i<r;i++){
            vec.push_back(matrix[u][i]);
        }
        res = bi_search(vec, target);
        if(res.first){
            return true;
        }
        pos = vec[res.second] > target ? res.second : res.second + 1;
        r = l + pos;
        if(r-l<1) break;

        // 左
        vec.clear();
        for(int i=u;i<d;i++){
            vec.push_back(matrix[i][l]);
        }
        res = bi_search(vec, target);
        if(res.first){
            return true;
        }
        pos = vec[res.second] > target ? res.second : res.second + 1;
        d = u + pos;
        if(d-u<1) break;

        // 下
        vec.clear();
        for(int i=l;i<r;i++){
            vec.push_back(matrix[d-1][i]);
        }
        res = bi_search(vec, target);
        if(res.first){
            return true;
        }
        pos = vec[res.second] > target ? res.second - 1 : res.second;
        l = l+pos+1;
        if(r-l<1) break;

        // 右
        vec.clear();
        for(int i=u;i<d;i++){
            vec.push_back(matrix[i][r-1]);
        }
        res = bi_search(vec, target);
        if(res.first){
            return true;
        }
        pos = vec[res.second] > target ? res.second - 1 : res.second;
        u = u+pos + 1;
        if(d-u<1) break;
    }
    return false;
  }
};

int main(){
    //[[3,6,9,12,17,22],[5,11,11,16,22,26],[10,11,14,16,24,31],[10,15,17,17,29,31],[14,17,20,23,34,37],[19,21,22,28,37,40],[22,22,24,32,37,43]]
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    // vector<vector<int>> matrix = {
    //     {3,6,9,12,17,22},
    //     {5,11,11,16,22,26},
    //     {10,11,14,16,24,31},
    //     {10,15,17,17,29,31},
    //     {14,17,20,23,34,37},
    //     {19,21,22,28,37,40},
    //     {22,22,24,32,37,43}
    // };

    auto res = Solution().searchMatrix(matrix, 20);
    cout<<res<<endl;
    return 0;
}