#include <bits/stdc++.h>

using namespace std;

//not really ufds, solved it without
int main(){
    int n, m;
    cin >> n >> m;
    while (!cin.eof()){
        bool wake = true;
        set<char> awake;
        map<char, set<char>> con;
        char a, b, c;
        cin >> a >> b >> c;
        awake.insert(a); awake.insert(b); awake.insert(c);
        for (int i = 0; i < m; i++){    
            cin >> a >> b;
            if (!awake.count(a)) con[a].insert(b);
            if (!awake.count(b)) con[b].insert(a);
        }
        if (con.size() + awake.size() < n) wake = false;
        for (const auto& el : con) if (el.second.size() < 3) wake = false;

        int years = 0;
        while (!con.empty() && wake){
            years++;
            set <char> torem;
            for (const auto& s : con) {
                int cnt = 0;
                for (const auto& el : s.second) {
                    if (awake.count(el))cnt++;
                    if (cnt == 3) {
                        torem.insert(s.first);
                        break;
                    }
                }
            }
            if (torem.empty()) wake = false;
            for (const auto& el : torem) {
                con.erase(el);
                awake.insert(el);
            }
        }
        
        if (wake) cout << "WAKE UP IN, " << years << ", YEARS\n";
        else cout << "THIS BRAIN NEVER WAKES UP\n";
        cin >> n >> m;
    }
}