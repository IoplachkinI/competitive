#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v (2 * n, vector<int> (2 * n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            v[i][j] = v[i][j + n] = v[i + n][j] = v[i + n][j + n] = a;
        }

        for (int i = 0; i < 2 * n; i++) for (int j = 0; j < 2 * n; j++){
            if (i) v[i][j] += v[i-1][j];
            if (j) v[i][j] += v[i][j-1];
            if (i && j) v[i][j] -= v[i-1][j-1];
        }

        /*for (int i = 0; i < 2 * n; i++){
            for (int j = 0; j < 2 * n; j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }*/

        long long maxsum = v[0][0], cursum = 0;
        for (int i1 = 0; i1 < 2 * n; i1++) for (int j1 = 0; j1 < 2 * n; j1++)
        for (int i2 = i1; i2 < min(2 * n, i1 + n); i2++) for(int j2 = j1; j2 < min(2 * n, j1 + n); j2++){
            cursum = v[i2][j2];
            if (i1) cursum -= v[i1-1][j2];
            if (j1) cursum -= v[i2][j1-1];
            if (i1 && j1) cursum += v[i1-1][j1-1];
            maxsum = max(cursum, maxsum);
        }

        cout << maxsum << "\n";
    }
}