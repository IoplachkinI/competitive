#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    while (true){
        int n;
        cin >> n;
        if (cin.eof()) break;
        vector<vector<ll>> v(n, vector<ll>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            v[i][j] = a;
            if (i) v[i][j] += v[i-1][j];
            if (j) v[i][j] += v[i][j-1];
            if (i && j) v[i][j] -= v[i-1][j-1];
        }

        long long maxsum = 0;
        for (int i1 = 0; i1 < n; i1++) for (int j1 = 0; j1 < n; j1++)
        for (int i2 = i1; i2 < n; i2++) for (int j2 = j1; j2 < n; j2++) {
            long long sum = 0;
            sum += v[i2][j2];
            if (i1) sum -= v[i1-1][j2];
            if (j1) sum -= v[i2][j1-1];
            if (i1 && j1) sum += v[i1-1][j1-1];
            if (sum > maxsum) maxsum = sum;
        }
        cout << maxsum << '\n';
    }
}