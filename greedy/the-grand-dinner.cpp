#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    vector<ll> a;
    vector<vector<ll>> res;
    vector<pair<ll, ll>> b;
    vector<ll> debug;
    while (true){
        bool good = true;
        ll m, n;
        cin >> m >> n;
        if (!m && !n) break;

        a.assign(m, 0);
        res.assign(m, vector<ll> ());
        b.assign(n, {0, 0});
        debug.assign(n, 0);

        for (ll i = 0; i < m; i++){
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++){
            cin >> b[i].first;
            debug[i] = b[i].first;
            b[i].second = i + 1;  
        }

        for (ll i = 0; i < m && good; i++){
            sort(b.rbegin(), b.rend());
            for (ll j = 0; j < a[i] && good; j++){
                if (!b[j].first) 
                    good = false;
                b[j].first--;
                debug[b[j].second - 1]--;
                res[i].push_back(b[j].second);
            }
        } 

        if (!good) cout << "0\n";
        else {
            cout << "1\n";
            for (ll i = 0; i < m; i++){
                for (ll j = 0; j < res[i].size(); j++){
                    if (j) cout << " ";
                    cout << res[i][j];
                }
                cout << "\n";
            }
        }
        
        }
}