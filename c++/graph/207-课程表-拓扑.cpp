#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
#define maxn (2000 + 5)
  unordered_set<int> graph_in[maxn];  // 入边
  unordered_set<int> graph_out[maxn]; // 入边
  int visited[maxn] = {0};
  void buildgraph(vector<vector<int>> &prerequisites) {
    for (auto &vec : prerequisites) {
      graph_in[vec[1]].insert(vec[0]);
      graph_out[vec[0]].insert(vec[1]);
    }
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    buildgraph(prerequisites);

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (graph_in[i].size() == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int v = q.front();
      q.pop();
     
      for (auto &i : graph_out[v]) {
        graph_in[i].erase(v);
        if (graph_in[i].size() == 0) {
          q.push(i);
        }
      }

      visited[v] = 1;
    }

    for (int i = 0; i < numCourses; i++) {
      if (visited[i] == 0) {
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
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  cout << Solution().canFinish(20, prerequisites) << endl;
  return 0;
}