#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(string &s, int st, int ed) {
        int i=st;
        int j=ed-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        int st = 0;
        while(st+2*k<=n){
            reverseString(s, st, st+k);
            st += 2*k;
        }
        if(st+k<=n) reverseString(s, st, st+k);
        else reverseString(s, st, n);
        return s;
    }
};

#include <iostream>
int main(){
    cout << Solution().reverseStr("abcdefg", 8);
    return 0;
}