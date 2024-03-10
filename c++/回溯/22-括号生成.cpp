#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int n;
    vector<string> res;

    void dfs(int total_left, int unmatch_left, string s){
        if(total_left == n){
            for(int i=0;i<unmatch_left;i++) s+=")";
            res.push_back(s);
            return;
        }

        dfs(total_left+1, unmatch_left+1, s+"(");
        if(unmatch_left>0)
            dfs(total_left, unmatch_left-1, s+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs(0, 0, "");
        return res;
    }
};