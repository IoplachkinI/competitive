#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int d;
        cin >> d;

        vector<pair<pair<int, int>, string>> v (d);
        for (int i = 0; i < d; i++){
            string str;
            int a, b;
            cin >> str >> a >> b;
            v[i] = {{a, b}, str};
        }
        sort(v.begin(), v.end());

        int q;
        cin >> q;
        
        while (q--){
            string str = "";
            int p;
            cin >> p;
            if (v[0].first.first > p) str = "UNDETERMINED";
            for (const auto& el : v) {
                if (p >= el.first.first && p <= el.first.second){
                    if (!str.compare("")) str = el.second;
                    else str = "UNDETERMINED";
                } 
                if (!str.compare("UNDETERMINED")) break;
            }
            if (!str.compare("")) str = "UNDETERMINED";
            cout << str << '\n';
        }

        if (t) cout << '\n';
    }
}