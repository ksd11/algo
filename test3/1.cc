#include<bits/stdc++.h>
using namespace std;

int main(){

    int *a = new int(1);
    int *b = std::move(a);
    // unique_ptr<int> a = make_unique<int>(1);
    // auto b = std::move(a);

    cout << *a << " " << *b << endl;
}