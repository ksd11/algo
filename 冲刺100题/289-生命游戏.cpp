#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int, int>> pos = {{-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int live(vector<vector<int>>& board, int m, int n, int x, int y){
        int res = 0;
        for(int i=0;i<pos.size();i++){
            int xx = x + pos[i].first;
            int yy = y + pos[i].second;
            if(xx >= 0 && xx < m && yy  >= 0 && yy<n && board[xx][yy]) res++;
        }
        return res;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        auto board_cp = board;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live_ = live(board_cp, m, n, i, j);
                if(board[i][j]){
                    // 活
                    if(live_ < 2 || live_ > 3) board[i][j] = 0;
                }else{
                    if(live_ == 3) board[i][j] = 1;
                }
            }
        }
    }
};

int main(){
    vector<vector<int>> vec = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution().gameOfLife(vec);
    return 0;
}