#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    while (n--){
        ll a, b, c;
        cin >> a >> b >> c;
        vector<vector<vector<ll>>> v (a, vector<vector<ll>>(b, vector<ll>(c)));
        for (ll i = 0; i < a; i++)
            for (ll j = 0; j < b; j++)
                for (ll k = 0; k < c; k++)
                    {
                        ll l;
                        cin >> l;
                        v[i][j][k] = l;
                        if (i) v[i][j][k] += v[i-1][j][k];
                        if (j) v[i][j][k] += v[i][j-1][k];
                        if (k) v[i][j][k] += v[i][j][k-1];
                        if (i && j) v[i][j][k] -= v[i-1][j-1][k];
                        if (i && k) v[i][j][k] -= v[i-1][j][k-1];
                        if (j && k) v[i][j][k] -= v[i][j-1][k-1];
                        if (i && j && k) v[i][j][k] += v[i-1][j-1][k-1];
                    }

        ll maxsub = LONG_LONG_MIN;
        for (ll i1 = 0; i1 < a; i1++) for (ll j1 = 0; j1 < b; j1++) for (ll k1 = 0; k1 < c; k1++)
        for (ll i2 = i1; i2 < a; i2++) for (ll j2 = j1; j2 < b; j2++) for (ll k2 = k1; k2 < c; k2++){
            ll sub = v[i2][j2][k2];
            if (i1) sub -= v[i1-1][j2][k2];
            if (j1) sub -= v[i2][j1-1][k2];
            if (k1) sub -= v[i2][j2][k1-1];
            if (i1 && j1) sub += v[i1-1][j1-1][k2];
            if (i1 && k1) sub += v[i1-1][j2][k1-1];
            if (j1 && k1) sub += v[i2][j1-1][k1-1];
            if (i1 && j1 && k1) sub -= v[i1-1][j1-1][k1-1];
            if (sub > maxsub) maxsub = sub;
        }

        cout << maxsub << '\n';
        if (n) cout << "\n";
    }
}