#include<iostream>
#include <queue>
using namespace std;

const int EXPIRE = 10;

struct RTT_package{
    unsigned long long arrival_time;
    int value;

    bool is_expire(unsigned long long time){
        return time - arrival_time >= EXPIRE;
    }
};

priority_queue<RTT_package>queue;

int reveice(){
    int v;
    while(cin >> v){
        queue.push(RTT_package{get_time(), v});
    }
}

int get_max(){
    while(!queue.empty()){
        RTT_package package = queue.pop();
        if (package.is_expire(get_time())){
            continue;
        }else{
            return package.value;
        }
    }
}

int main(int argc,char *argv[]){
    
    do reveive();
    do get_max();
    return 0;
}
