#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;
    int n = s.length();

    int small_cnt = 0;

    for(int i=1;i<n;i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            small_cnt++;
        }
    }

    int first = 1;
    if(s[0] >= 'a' && s[0] <= 'z') first = 0;

    // 1.都是小写
    int res = first + n-1-small_cnt;

    // 2.都是大写
    res = min(res, small_cnt + 1 - first);

    // 3.第一个字符大写，后面小写
    res = min(res, 1-first+n-1-small_cnt);

    cout << res <<endl;


    return 0;
}