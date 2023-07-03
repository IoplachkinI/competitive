#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int d, b;
        cin >> d >> b;

        int cur = 1;
        int res = 1;
        while (cur != d){
            if (((b - 1) / (1 << (cur - 1))) % 2 == 0) {
                res <<= 1;
            }
            else res = (res << 1) + 1;
            cur++;
        }

        cout << res << '\n';

    }
}