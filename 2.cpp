#include<iostream>
#include <queue>
using namespace std;


// queue<int> q;
int max_window[20] = {0};
int min_window[20] = {0};

// 当前指向的windows位置
int cur = 0;
const int EXPIRE = 10;

void reveice(){
    int v;
    while(cin >> v){
        int pos = (cur+EXPIRE)%20;
        if (max_window[pos] < v){
            max_window[pos] = v;
        }
        if (min_window[pos] > v){
            min_window[pos] = v;
        }
    }
}

// 窗口往前滑动
void tick(){
    max_window[cur] = -1e9;
    min_window[cur] = 1e9;
    cur += 1;
    cur %= 20;
}

// 获取最近10s
int get_max(){
    return max_window[cur];
}

int get_min(){
    return min_window[cur];
}


int main(int argc,char *argv[]){
    int v;
    do reveice();
    do tick(); // 一秒执行一次
    do get_max();
    return 0;
}