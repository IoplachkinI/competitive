#include <bits/stdc++.h>

using namespace std;

int main(){
    int s, b;
    cin >> s >> b;

    while (s != 0){
        set<int> v;
        for (int i = 0; i <= s + 1; i++){
            v.insert(i);
        }
        while (b--){
            int l, r;
            string out;
            cin >> l >> r;
            
            int lb = *(--v.find(l)), rb = *v.upper_bound(r);

            if (lb == 0) out += '*';
            else out += to_string(lb);
            out += ' ';
            if (rb == s + 1) out += '*';
            else out += to_string(rb);  
            
            for (int i = l; i <= r; i++){
                v.erase(i);
            }

            out += '\n';
            cout << out;

        }
        cout << "-\n";
        cin >> s >> b;
    }
}