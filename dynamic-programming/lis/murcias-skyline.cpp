#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, _case = 0;
    cin >> t;
    while (t--){
        _case++;
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(2));
        vector<vector<long long>> lis (n, vector<long long>(2));
        vector<vector<long long>> lds (n, vector<long long>(2));
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i][1] = lis[i][1] = lds[i][1] = a;
        }

        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i][0] = lis[i][0] = lds[i][0] = a;
        }

        for (int i = 0; i < n; i++){
            for (int j = i - 1; j >= 0; j--){
                if(lis[j][0] + v[i][0] > lis[i][0] && lis[j][1] < v[i][1]) 
                    lis[i][0] = lis[j][0] + v[i][0];
                if(lds[j][0] + v[i][0] > lds[i][0] && lds[j][1] > v[i][1]) 
                    lds[i][0] = lds[j][0] + v[i][0];
            }
        }

        long long maxlis = 0, maxlds = 0;
        for (int i = 0; i < n; i++){
            maxlis = max(maxlis, lis[i][0]);
            maxlds = max(maxlds, lds[i][0]);
        }

        if (maxlis >= maxlds)
            printf ("Case %d. Increasing (%lld). Decreasing (%lld).\n", _case, maxlis, maxlds);
        else
            printf ("Case %d. Decreasing (%lld). Increasing (%lld).\n", _case, maxlds, maxlis);

    }
}