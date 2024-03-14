#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char &c:magazine){
            mp[c] += 1;
        }
        for(auto &c:ransomNote){
            if(!mp.count(c) || mp[c] == 0) return false;
            mp[c]--;
        }
        return true;
    }
};