#include <bits/stdc++.h>

using namespace std;

#define o cout

int main(){
    string str;
    getline (cin, str);
    while (str.compare("0")){
        map<string, set<string>> m;
        set <string> total;
        while (str.compare("1")){
            string name = str;
            m[name] = {};
            //o << "name = " << str << '\n';
            getline(cin, str);
            //o << "got 2\n";
            while (str.compare("1") && !isupper(str[0])){
                //o << "got 2\n";
                if (total.count(str)) {
                    for (auto& el : m) 
                        if (el.second.erase(str)) break;
                }
                else m[name].insert(str);
                getline(cin, str);
            }

            for (const auto& el : m[name]){
                total.insert(el);
            }

        }

        vector<pair<int, string>> v;
        for (const auto& el : m){
            v.push_back({el.second.size(), el.first});
            //o << el.second.size() << '\n';
        }
        sort(v.begin(), v.end(), [](pair<int, string> b, pair<int, string> a){
            if (b.first == a.first) return  (b.second.compare(a.second) < 0);
            else return b.first > a.first;
        });

        for (const auto& el : v){
            o << el.second << ' ' << el.first << '\n';
        }

        getline (cin, str);
        //o << "got 3\n";
    }
}