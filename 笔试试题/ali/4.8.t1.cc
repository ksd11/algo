#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> map_1 = {{'>',0}, {'<',1}, {'^',2}, {'v',3}};
unordered_map<char, int> map_2 = {{0, '>'}, {1,'<'}, {2, '^'}, {3,'v'}};
pair<int,int> dir[] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool not_valid(int x, int y, int n){
    return x < 1 || x > n || y < 1 || y > n;
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> mp(n+1, vector<char>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mp[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    int cnt = 0;
    while(cnt <= 1e6 && !not_valid(x, y, n)){
        auto direction = dir[map_1[mp[x][y]]];
        mp[x][y] = map_2[map_1[mp[x][y]] ^ 1];
        x += direction.first;   
        y += direction.second;
        cnt ++;
    }

    if(not_valid(x,y,n)) cout<<cnt<<endl;
    else cout << -1<<endl;
    return 0;
}