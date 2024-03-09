#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
#define maxn (2000 + 5)
  set<int> graph[maxn];
  int flag[maxn] = {0};
  int total;
  int is_visit[maxn] = {0};
  set<int> visited;
  set<int> visiting;
  void buildgraph(vector<vector<int>> &prerequisites) {
    for (auto &vec : prerequisites) {
      graph[vec[0]].insert(vec[1]);
    }
  }

  // 判断有无环
  bool dfs(int v) {
    if(visited.count(v) != 0) return false;

    visiting.insert(v); // 当前回合探访过的

    is_visit[v] = 1; // 当前回合visit
    
    for (auto &i : graph[v]) {
      if(i == v || is_visit[i]) return true; // 环
      if (dfs(i)) {
        return true;
      }
    }
    is_visit[v] = 0;
    return false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    total = numCourses;
    buildgraph(prerequisites);
    for(int i = 0; i < numCourses; i++){
      if(visited.count(i)) continue;

      auto cycle = dfs(i);
      visited = visiting;
      visiting.clear();
      if(cycle){
        return false;
      }
    }
    return true;
  }
};

int main() {
  // vector<vector<int>> prerequisites;
  // prerequisites.push_back({0, 10});
  // prerequisites.push_back({3, 18});
  // prerequisites.push_back({5, 5});
  // prerequisites.push_back({6, 11});
  // prerequisites.push_back({11, 14});
  // prerequisites.push_back({13, 1});
  // prerequisites.push_back({15, 1});
  // prerequisites.push_back({17, 4});
  vector<vector<int>> prerequisites = {{1,0},{0,1}};
  cout << Solution().canFinish(20, prerequisites) << endl;
  return 0;
}