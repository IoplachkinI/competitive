#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    while (!cin.eof()){
        vector<int> v (n);
        int maxn = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] > maxn) maxn = v[i];
            sum += v[i];
        }

        ll l = maxn, r = sum + 1, minn = LONG_LONG_MAX;

        while (l < r){
            ll cnt = 1, cursum = 0, mid = (l + r) / 2;
            for (const auto& el : v){
                cursum += el;
                if (cursum > mid) {
                    cnt++;
                    cursum = el;
                }
            }
            if (cnt > m) l = mid + 1;
            else {
                r = mid;
                if (mid < minn) minn = mid;
            }
        }

        cout << minn << '\n';
        cin >> n >> m;
    }
}