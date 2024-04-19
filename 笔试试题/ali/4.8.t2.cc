#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;  // 输入蛋糕数量和制作步骤数量
    vector<int> size(k), ti(k), wait(k);  // 初始化每个步骤的人数上限、所需时间和等待队列长度
    for(int i = 0; i < k; i++) {
        cin >> size[i] >> ti[i];  // 输入每个步骤的人数上限和所需时间
    }
    long long ans = 0;  // 初始化完成所有蛋糕所需的最小时间

    // pair<long long, int> -> 完成时间，当前步骤索引（已做完），-1表示新任务
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;  // 初始化优先队列，按完成时间升序排列
    for(int i = 0; i < n; i++) {
        q.push({0, -1});  // 初始时，所有蛋糕都未开始处理
    }
    while(!q.empty()) {
        pair<long long, int> nw = q.top();  // 取出当前最早完成的步骤
        q.pop();
        ans = nw.first;  // 更新完成时间
        int idx = nw.second;  // 当前步骤索引
        if(idx != -1) {  // 如果不是新的蛋糕开始
            if(wait[idx] > 0) {  // 如果当前步骤有等待队列
                q.push({nw.first + ti[idx], idx});  // 添加当前步骤的下一次完成时间
                --wait[idx];  // 等待队列长度减一
            }
            else {
                ++size[idx];  // 没有等待队列，当前步骤可用人数增加
            }
        }
        if(idx + 1 < k) {  // 如果还有下一个步骤
            ++idx;  // 移至下一步骤
            if(size[idx] > 0) {  // 如果下一步骤有可用人手
                --size[idx];  // 占用一个人手
                q.push({nw.first + ti[idx], idx});  // 计划下一步骤的完成时间
            }
            else {
                ++wait[idx];  // 如果下一步骤没有可用人手，当前蛋糕进入等待队列
            }
        }
    }
    cout << ans << endl;  // 输出完成所有蛋糕所需的最小时间
    return 0;
}

/*
Input:
3 3
2 1
2 2
3 1
Output:
6
*/