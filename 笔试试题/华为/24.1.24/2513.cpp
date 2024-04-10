#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef unsigned long long ull;
    bool check(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2, ull lcm, ull val){
        int mu1 = val / divisor1;
        int mu2 = val / divisor2;
        int cmm = val / lcm;
        ull total = val + cmm - mu1 - mu2; // 剩下可以作为两个数组的元素
        uniqueCnt1 -= (mu2-cmm);
        uniqueCnt2 -= (mu1-cmm);
        uniqueCnt1 = max(0, uniqueCnt1);
        uniqueCnt2 = max(0, uniqueCnt2);
        return uniqueCnt1+uniqueCnt2 <= total;
    } 

    // 最小公因数
    int gcd(int a,int b){
        while(b){
            int tmp = a;
            a = b;
            b = tmp%b;
        }
        return a;
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ull nums_sum = 0;
        ull R = (ull)divisor1 * ((uniqueCnt1+(divisor1-2))/(divisor1-1)) + \
                (ull)divisor2 * ((uniqueCnt2+(divisor2-2))/(divisor2-1));
        
        ull L = uniqueCnt1 + uniqueCnt2;

        ull lcm = ((ull)divisor1 * divisor2)/gcd(divisor1, divisor2); // 最小公倍数

        cout << L << " " << R << " " << lcm << endl;

        while(L<=R){
            ull mid = L + ((R-L)>>1);
            if(!check(divisor1, divisor2, uniqueCnt1, uniqueCnt2, lcm, mid)){
                L = mid+1; // 保证<L的位置都不可能成功
            }else{
                R = mid-1;
            }
        }
        return L;
    }
};

int main(){
    cout << Solution().minimizeSet(2, 4, 8, 2) << endl;
    return 0;
}