#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int _case = 0;
    while (true){
        _case++;
        int n;
        cin >> n;
        if (!n) break;
        vector<vector<int>> v(3 * n, vector<int>(3));
        for (int i = 0; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            v[3*i] = {a, b, c};
            v[3*i+1] = {a, c, b};
            v[3*i+2] = {b, c, a};
        }

        sort(v.begin(), v.end(), [](vector<int> i, vector<int> j){
            return (i[0]*i[1] < j[0]*j[1]);
        });

        vector<ll> lis(3 * n);
        for (int i = 0; i < 3*n; i++){
            lis[i] = v[i][2];
            for (int j = i - 1; j >= 0; j--){
                if (max(v[j][0], v[j][1]) >= max(v[i][0], v[i][1]) ||
                    min(v[j][0], v[j][1]) >= min(v[i][0], v[i][1])) 
                        continue;
                lis[i] = max(lis[i], lis[j] + v[i][2]);
            }
        }

        ll res = *max_element(lis.begin(), lis.end());
        printf("Case %d: maximum height = %lld\n", _case, res);
    }  
}