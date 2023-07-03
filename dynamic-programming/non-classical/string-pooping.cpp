#include <bits/stdc++.h>

using namespace std;

string str;
set<string> checked;

bool rec(string str){
    if (str.size() == 0) return true;
    if (checked.count(str)) return false;
    int start = 0, end = 0;
    while (true){
        start = str.find('a', end);
        if (start == string::npos) break;
        end = str.find('b', start);
        if (end == string::npos) end = str.size();
        if (end - start < 2) continue;
        string substr2 = "";
        if (end != str.size()) substr2 = str.substr(end, str.size() - end);
        if (rec(str.substr(0, start) + substr2)) return true;
    }
    end = 0;
    while (true){
        start = str.find('b', end);
        if (start == string::npos) break;
        end = str.find('a', start);
        if (end == string::npos) end = str.size();
        if (end - start < 2) continue;
        string substr2 = "";
        if (end != str.size()) substr2 = str.substr(end, str.size() - end);
        if (rec(str.substr(0, start) + substr2)) return true;
    }
    checked.insert(str);
    return false;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> str;
        cout << (int)rec(str) << '\n';

    }
}