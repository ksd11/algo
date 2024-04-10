#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;
    int len = s.length();
    map<char, int> score = {{'r',1}, {'g', 2}, {'b', 3}};
    int res = 0;
    char last_char = 0;
    int cnt = 0;

    for(int i=0;i<len;i++){
        if(s[i] == last_char){
            res += cnt;
            cnt++;
        }else{
            last_char = s[i];
            cnt=1; 
        }
        res += score[s[i]];
    }
    cout << res << endl;

    return 0;
}