#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    map<string, string> m;

    getline(cin, str);
    while (str.size() > 0){
        m[str.substr(str.find(' ') + 1)] = str.substr(0, str.find(' '));
        getline(cin, str);
    }

    getline(cin, str);
    while (str.size() > 0){
        if (!m.count(str)) cout << "eh\n";
        else cout << m[str] << '\n';
        getline(cin, str);
    }
}