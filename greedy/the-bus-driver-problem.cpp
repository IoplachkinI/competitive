#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    while (true){
        ll n, d, r;
        cin >> n >> d >> r;
        if (!n && !d && !r) break;

        vector<ll> morning (n);
        vector<ll> evening (n);
        for (ll i = 0; i < n; i++){
            cin >> morning[i];
        }
        for (ll i = 0; i < n; i++){
            cin >> evening[i];
        }
        sort(morning.begin(), morning.end());
        sort(evening.rbegin(), evening.rend());
        ll res = 0;
        for (ll i = 0; i < n; i++){
            ll penalty = morning[i] + evening[i] - d;
            if (penalty <= 0) continue;
            res += penalty * r;
        }
        cout << res << '\n';
    }
}