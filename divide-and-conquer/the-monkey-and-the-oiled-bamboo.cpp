#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int cnt = 0;
    while (t--){
        cnt++;
        int n, maxdiff = 0;
        cin >> n;
        vector<int> v (n + 1);
        v[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
            if (i > 0 && v[i] - v[i - 1] > maxdiff) maxdiff = v[i] - v[i - 1];
        }

        bool good = true;
        int k = maxdiff;
        for (int i = 1; i <= n && good; i++){    
            if (v[i] - v[i - 1] > k) good = false;
            else if (v[i] - v[i - 1] == k) k--;
        }

        if (!good) maxdiff++;
        printf("Case %d: %d\n", cnt, maxdiff);

    }
}