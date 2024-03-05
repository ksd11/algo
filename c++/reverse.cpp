#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    reverse(a.begin(), a.end());
    for(auto& i : a){
        cout << i << endl;
    }
    return 0;
}