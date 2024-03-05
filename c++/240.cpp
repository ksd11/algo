#include <vector>
#include<iostream>
using namespace std;

// 二分，复杂度较高
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

  // 搜索 [u:d, l:r]矩阵范围，不包括d,r
  bool searchMatrixHelper(vector<vector<int>> &matrix, int target, int l, int r,
                          int u, int d) {

    if(l>=r || u>=d){
        return false;
    }

    vector<int> vec;
    int m = d - u;
    int n = r - l;

    if(m==1){
        for(int i=l;i<r;i++){
            vec.push_back(matrix[u][i]);
        }
        return bi_search(vec, target).first;
    }

    if(n==1){
        for(int i=u;i<d;i++){
            vec.push_back(matrix[i][l]);
        }
        return bi_search(vec, target).first;
    }


    for (int i = 0; i < n && i < m; i++) {
      vec.push_back(matrix[u + i][l + i]);
    }
    auto res = bi_search(vec, target);
    if (res.first) {
      return true;
    }

    int pos = vec[res.second] > target ? res.second : res.second + 1;

    return searchMatrixHelper(matrix, target, l+pos, r, u, u+pos) ||
           searchMatrixHelper(matrix, target, l, l+pos, u+pos, d);
  }

  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    return searchMatrixHelper(matrix, target, 0, matrix[0].size(), 0, matrix.size());
  }
};

int main(){
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    auto res = Solution().searchMatrix(matrix, 25);
    cout<<res<<endl;
    return 0;
}