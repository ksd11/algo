#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        if(haystack.find(needle) != haystack.size()){
            return index;
        }
        return -1;
    }
};