#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int cas = 0;
    while (t--){
        cas++;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            if (c == '.') v[i] = 1;
            else v[i] = 0;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i]) {
                cnt++;
                i += 2;
            }
        }
        printf("Case %d: %d\n", cas, cnt);
    }
}