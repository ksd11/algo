#include <iostream>
#include <stack>
using namespace std;

class Solution {

    string parseNumber(string s, int *num){
        int res = 0;
        int cnt = 0;
        char c = s[cnt];
        while(c >= '0' && c <= '9'){
            res *= 10;
            res += c - '0';
            cnt++;
            c = s[cnt];
        }
        *num = res;
        return s.substr(cnt);
    }

    string parseString(string s, string *res, bool skip=true){
        // int size = s.size();
        int cnt = skip ? 1:0; // skip '['
        int repeat_time = 0;
        while(cnt < s.size()){
            char c = s[cnt];
            if(c == ']'){
                break;
            }

            if(c == '['){
                string tmp;
                s = parseString(s.substr(cnt), &tmp);
                cnt = 0;
                for(int i=0;i<repeat_time;i++){
                    res->append(tmp);
                }
            }else if(s[cnt] >= '0' && s[cnt] <= '9'){
                s = parseNumber(s.substr(cnt), &repeat_time);
                cnt = 0;
            }else{
                res->push_back(c);
                cnt++;
            }
        }
        return cnt+1>s.size() ? "":s.substr(cnt+1);
    }

public:
    string decodeString(string s) {
        string res;
        parseString(s, &res, false);
        return res;
    }
};

#include <iostream>
int main(){
    // cout << Solution().decodeString("3[a]2[bc]");
    // cout << Solution().decodeString("3[a2[c]]");
    cout << Solution().decodeString("2[abc]3[cd]ef");
    return 0;
}