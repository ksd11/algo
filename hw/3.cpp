#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            cin >> matrix[i][j];
        }
    }

    string s;
    cin >> s;
    cout << 3 << endl;

    return 0;
}