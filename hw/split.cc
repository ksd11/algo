#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::string str = "这是,一个,测试,字符串";
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> result;

    while (std::getline(ss, token, ',')) {
        result.push_back(token);
    }

    for(auto &s:result)
        cout <<  s<<endl;

    // 此时，result中的元素为："这是", "一个", "测试", "字符串"
}
