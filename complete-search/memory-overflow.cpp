#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, cas = 0;
    cin >> t;
    while (t--){
        cas++;
        int n, k, cnt = 0;
        cin >> n >> k;
        map<char, int> m;
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            if (m.count(c) && i - m[c] <= k) cnt++;
            m[c] = i;
        }
        printf("Case %d: %d\n", cas, cnt);
    }
}