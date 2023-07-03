#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll t;
    cin >> t;

    while (t--){
        ll a;
        cin >> a;
        ll n = ll((-1.0 + sqrtl(1.0 + 8.0 * a)) / 2.0);
        ll res = a - (n + 1) * n / 2;
        if (!res) res = n;
        cout << res << '\n';
    }
}