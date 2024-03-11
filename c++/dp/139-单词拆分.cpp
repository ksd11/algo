#include <iostream>
#include<vector>
using namespace std;

class Solution {
    bool is_match(string& word, string &s){
        int i=0, j=0;
        while(i<word.length() && j < s.length() && word[i] == s[j]){
            i++;
            j++;
        }
        return i==word.length();
    }

    bool wordBreakWithSeq(string s, vector<string>& wordDict, vector<int> &match, int idx){
        if(s.size()==0) return true;
        if(match[idx] != -1) return match[idx];

        for(auto& word : wordDict){
            if(is_match(word,  s)){
                if(word.length() >= s.length()) return match[idx] = true;
                if(wordBreakWithSeq(s.substr(word.length()), wordDict, match, idx+ word.length()))
                    return match[idx] = true;
            }
        }
        return match[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> match(s.size(), -1);
        return wordBreakWithSeq(s, wordDict, match, 0);
    }
};

#include <iostream>
int main(){
    // string s = "leetcode";
    // vector<string> wordDict = {"leet", "code"};
    // string s = "applepenapple";
    // vector<string> wordDict = {"apple", "pen"};
    string s = "a";
    vector<string> wordDict = {"a"};
    cout<< Solution().wordBreak(s, wordDict);
    return 0;
}