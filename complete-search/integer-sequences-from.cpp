#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int c;
    cin >> c;
    while (c--){
        int k;
        cin >> k;
        int v [1000000];
        for (int i = 0; i <= k; i++){
            cin >> v[i];
        }

        int d, a;
        ll d1 = 0;
        cin >> d >> a;

        for (int i = 1;; i++){
            d1 += d * i;
            if (a <= d1) {
                ll res = 0;
                for (int j = 0; j <= k; j++) res += ll(v[j]) * ll(powl(i, j));
                cout << res << '\n';
                break;
            }
        }

    }
}