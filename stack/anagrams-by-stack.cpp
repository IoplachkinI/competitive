#include <bits/stdc++.h>

using namespace std;

#define o cout

void check(string a, string b, stack<char> res, stack<char> mid, string path){
    if (res.size() > 0 && res.top() != b[res.size() - 1]) return;
    if (a.length() == 0 && mid.size() == 0 && res.size() == b.length()) cout << path << '\n';

    if (a.length() > 0){
        mid.push(a[0]);
        if (a.length() == b.length()) check(a.substr(1, a.length() - 1), b, res, mid, path + "i");
        else check(a.substr(1, a.length() - 1), b, res, mid, path + " i");
        mid.pop();
    }

    if (mid.size() == 0) return;
    res.push(mid.top());
    mid.pop();
    check(a, b, res, mid, path + " o");
}

int main(){
    string a, b; // a transforms into b
    cin >> a >> b;
    while (!cin.eof()){
        cout << "[\n";
        check(a, b, {}, {}, "");
        cout << "]\n";
        cin >> a >> b;  
    }
}