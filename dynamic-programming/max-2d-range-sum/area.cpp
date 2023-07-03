#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    long long c = 0;
    while (t--){
        c++;
        long long n, m, k;
        cin >> n >> m >> k;
        vector<vector<long long>> v(n, vector<long long> (m));
        for (long long i = 0; i < n; i++) for(long long j = 0; j < m; j++){
            cin >> v[i][j];
            if (i) v[i][j] += v[i-1][j];
            if (j) v[i][j] += v[i][j-1];
            if (i && j) v[i][j] -= v[i-1][j-1];
        }

        long long minsum = LONG_LONG_MAX, cursum = -1, maxarea = 0, curarea = 0;
        for (long long i1 = 0; i1 < n; i1++) for (long long j1 = 0; j1 < m; j1++)
        for (long long i2 = i1; i2 < n; i2++) for (long long j2 = j1; j2 < m; j2++){
            cursum = v[i2][j2];
            if (i1) cursum -= v[i1-1][j2];
            if (j1) cursum -= v[i2][j1-1];
            if (i1 && j1) cursum += v[i1-1][j1-1];

            if (cursum > k) break;
            curarea = (i2-i1+1) * (j2-j1+1);
            if (curarea > maxarea) {
                maxarea = curarea;
                minsum = cursum;
            }
            if (curarea == maxarea){
                minsum = min(minsum, cursum);
            }
        }  

        if (minsum == LONG_LONG_MAX) minsum = 0;
        printf("Case #%lld: %lld %lld\n", c, maxarea, minsum);
    }
}