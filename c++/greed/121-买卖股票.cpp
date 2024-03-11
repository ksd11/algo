#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> min_val(prices.size(), 1e5);
        vector<int> max_val(prices.size(), -1e5);

        min_val[0] = prices[0];
        for(int i=1;i<prices.size();i++){
            min_val[i] = min(prices[i], min_val[i-1]);
        }

        max_val[prices.size()-1] = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--){
            max_val[i] = max(max_val[i+1], prices[i]);
        }

        int res = 0;
        for(int i=0;i<prices.size();i++){
            res = max(res, max_val[i]-min_val[i]);
        }
        return res;
    }
};