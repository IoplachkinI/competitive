#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    while (n){
        cnt++;
        vector<int> v (n);
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = i - 1; j > -1; j--){
                sums.push_back(v[i] + v[j]);
            }
        }

        sort(v.begin(), v.end());
        sort(sums.begin(), sums.end());
        int m;
        cin >> m;
        printf("Case %d:\n", cnt);
        for (int i = 0; i < m; i++){
            int q;
            cin >> q;
            int res = INT32_MIN;
            for (const auto& el : sums) if (abs(q - res) > abs(q - el)) res = el;
            printf("Closest sum to %d is %d.\n", q, res);
        }
        cin >> n;
    }
}