#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if (!n) break;

        multiset<pair<int, int>> m;
        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            m.insert({a, b});
        }

        bool good = true;
        while (!m.empty() && good){
            int a = (*m.begin()).first;
            int b = (*m.begin()).second;

            if (m.erase({a, b}) != m.erase({b, a})) good = false;
        }

        if (!good) cout << "NO\n";
        else cout << "YES\n";
    }    
}