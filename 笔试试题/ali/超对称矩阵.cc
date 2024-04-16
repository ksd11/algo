#include<bits/stdc++.h>
using namespace std;


void update(int i, int j, vector<vector<int>> &vec, vector<vector<bool>> &visit, int &max_val){
    if(vec[i][j] > max_val) max_val = vec[i][j];
    visit[i][j] = true;
}


int main(){

    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> vec[i][j];
        }
    }

    

    /**
     i,j -> j,n-1-i
        -> n-1-i, n-1-j
        -> n-1-j, i
    */
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                int max_val = 0;
                update(i, j, vec, visit,  max_val);
                update(j, n-1-i, vec, visit, max_val);
                update(n-1-i, n-1-j, vec, visit, max_val);
                update(n-1-j, i, vec, visit, max_val);
                res += 4*max_val-vec[i][j]-vec[j][n-1-i]-vec[n-1-i][n-1-j]-vec[n-1-j][i];
            }
        }
    }

    cout << res << endl;


    return 0;
}