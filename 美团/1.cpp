#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mp(n, vector<int>(n, 0));
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            mp[i][j] = s[j]-'0';
        }
    }

    // i,j,k 代表 第i行，第J到第k列0的个数
    vector<vector<vector<int>>> nums0(n, vector<vector<int>>(n, vector<int>(n, 0)));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                if(k == j) nums0[i][j][k] = mp[i][k] == 0;
                else nums0[i][j][k] = nums0[i][j][k-1] + (mp[i][k] == 0);
            }
        }
    }

    int size = 2;
    vector<int> res(n+1,0);
    for(;size<=n;size+=2){
        int target = size * size / 2;
        for(int i=0;i<n && i+size<=n;i++){
            for(int j=0;j<n && j+size<=n;j++){
                int count = 0;
                for(int k=i;k<i+size;k++) // 行
                    count += nums0[k][j][j+size-1];
                if(count == target) res[size]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<endl;
    }

}
// 64 位输出请用 printf("%lld")