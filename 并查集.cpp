
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, int> p;

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void union_(int a, int b) {
  int pa = find(a), pb = find(b);
  p[pa] = pb;
}

int main(){
    cout << find(1);
    return 0;
}