#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if (!n) break;
        bool first = true;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            if (!a) continue;

            if (!first) cout << ' ';
            cout << a;
            first = false;
        }
        if (first) cout << '0';
        cout << '\n';
    }
}