#include<vector>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<set<char>> res;
        for(auto&c : s){
            if(res.size()==0){
                set<char> myset;
                myset.insert(c);
                res.push_back(myset);
            }else{
                bool find = false;
                for(int i=res.size()-1;i>=0;i--){
                    if(res[i].count(c)){
                        if(i!=res.size()-1){
                            // 合并 i~ res.size()-1
                            find = true;
                            set<char> myset;
                            for(int j=res.size()-1;j>=i;j--){
                                myset.insert(res[j].begin(), res[j].end());
                                res.pop_back();
                            }
                            res.push_back(myset);
                        }else{
                            find = true;
                            break;
                        }
                    }
                }
                if(!find){
                    // add new set
                    set<char> myset;
                    myset.insert(c);
                    res.push_back(myset);
                }
            }
        }

        vector<int> nums;
        int cnt = 0;
        int split = 0;
        for(int i=0;i<s.size();i++){
            if(!res[cnt].count(s[i])){
                nums.push_back(i-split);
                split = i;
                cnt++;
            }
        }
        nums.push_back(s.size()-split);
        return nums;
    }
};

int main(){
    string s = "ababcbacadefegdehijhklij";
    vector<int> vec = Solution().partitionLabels(s);
    for(auto &i:vec){
        cout<<i<<endl;
    }
    return 0;
}