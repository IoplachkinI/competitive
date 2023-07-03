#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++){
            cin >> v[i];
        }

        ll cnt = 1, sum = 0;
        for (ll i = 0; i < n - 1; i++){
            if (v[i + 1] > sum + v[i]) {
                cnt++;
                sum += v[i];
            }
        }

        cout << cnt << '\n';
    }
}