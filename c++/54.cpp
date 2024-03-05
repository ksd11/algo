#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int i=0, j=0;
        while(res.size() != m*n){
            
            // left -> right
            while(res.size() != m*n && j<n-i){
                res.push_back(matrix[i][j]);
                j++;
            }

            // up -> down
            j--;
            i++;
            while(res.size() != m*n && i<m-(n-1-j)){
                res.push_back(matrix[i][j]);
                i++;
            }

            // right -> left
            i--;
            j--;
            while(res.size() != m*n && j>m-i-2){
                res.push_back(matrix[i][j]);
                j--;
            }

            j++;
            i--;
            while(res.size() != m*n && i>j){
                res.push_back(matrix[i][j]);
                i--;
            }
            i++;
            j++;
        }

        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> res = Solution().spiralOrder(matrix);
    for(auto &i : res){
        cout<<i<<endl;
    }
    return 0;
}