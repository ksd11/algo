#include<bits/stdc++.h>
using namespace std;

struct Entry{
    unsigned long long time;
    string client;
    string factor;

    bool operator==(const Entry& entry) const{
        return time == entry.time && \
             client == entry.client && \
            factor == entry.factor;
    }
};

struct MyHash {
    std::size_t operator()(const Entry& s) const {
        std::size_t h1 = std::hash<std::string>{}(s.client);
        std::size_t h2 = std::hash<std::string>{}(s.factor);
        std::size_t h3 = std::hash<unsigned long long>{}(s.time);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

Entry parse(string data, int &num){
    int len = data.length();
    for(int i=0;i<len;i++){
        if(data[i] == ',') data[i]=' ';
    }
    stringstream ss(data);
    Entry entry;
    ss >> entry.time >> entry.client >> entry.factor >> num;
    return entry;
}

int main(){
    int n;
    cin >> n;
    unordered_map<Entry, int, MyHash> data_map;
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int num;
        Entry e = parse(s, num);
        if(data_map.count(e)){
            // data_map[e] = max(data_map[e], num);
            // data_map[e] = data_map[e], nu;
            continue;
        }else{
            data_map[e] = num;
        }
    }

    int m;
    cin >> m;
    string s;
    unordered_map<string, int> mp;
    for(int i=0;i<m;i++){
        cin >> s;
        auto pos = s.find(',');
        string factor = string(s.begin(), s.begin()+pos);
        int price = atoi(string(s.begin()+pos+1, s.end()).c_str());
        mp[factor] = price;
        // cout << factor <<" " << price<<endl;
    }

    map<string, int> res;
    for(auto &p:data_map){
        Entry entry = p.first;
        int num = p.second;

        if(num < 0 || num > 100){
            continue;
        }

        res[entry.client] += mp[entry.factor] * num;
        // cout << client << factor << price << endl;
    }

    for(auto&p : res){
        cout <<p.first<<","<<p.second<<endl;
    }



    return 0;
}