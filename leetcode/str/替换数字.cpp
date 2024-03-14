#include<iostream>
using namespace std;


string func(string &s){
    string res;
    for(auto &c:s){
        if(c>='0' && c <= '9'){
            res += "number";
        }else{
            res.push_back(c);
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    cout << func(s) << endl;
    return 0;
}