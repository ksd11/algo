#include<bits/stdc++.h>
using namespace std;

#define MAXN 50005

/* https://zhuanlan.zhihu.com/p/93795692 */

/*
    获取最低位的字节
*/
#define lowbit(x) ((x) & (-x))

// 从1开始计数
int tree[MAXN]; 

inline void update(int i, int x)
{
    for (int pos = i; pos < MAXN; pos += lowbit(pos))
        tree[pos] += x;
}

// 计算前n个元素的和
inline int query(int n)
{
    int ans = 0;
    for (int pos = n; pos; pos -= lowbit(pos))
        ans += tree[pos];
    return ans;
}

// 计算a到b的和
inline int query(int a, int b)
{
    return query(b) - query(a - 1);
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    for(int i=0;i<arr.size();i++){
        update(i+1, arr[i]);
    }

    cout << query(3) << endl;
    cout << query(3,5) << endl;

    return 0;
}