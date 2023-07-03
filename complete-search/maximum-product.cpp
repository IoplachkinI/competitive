#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cas = 0;
    cin >> n;
    while (!cin.eof()){
        cas++;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        long long maxprod = 0;
        long long maxnum = 0;
        for (int i = 0; i < n; i++){
            if (v[i] > maxnum) maxnum = v[i];
            for (int j = i + 1; j < n; j++){
                long long prod = v[i] * v[j];
                for (int k = i + 1; k < j; k++){
                    prod *= v[k];
                }
                if (prod > maxprod) maxprod = prod;
            }
        }
        if (maxnum > maxprod) maxprod = maxnum;
        printf("Case #%d: The maximum product is %lld.\n\n", cas, maxprod);

        cin >> n;
    }
}