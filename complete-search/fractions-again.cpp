#include <bits/stdc++.h>

using namespace std;

int main(){
    int k = -1; cin >> k;
    while(!cin.eof()){
        vector<pair<long long, long long>> v;
        for (int i = k + 1; i <= k * 2; i++){
            long double j = 1.0 / (1.0 / (long double) k - 1.0 / (long double) i);
            if (fabsl(j - round(j)) < 0.00001) v.push_back({lround(j), i});
        }
        printf("%d\n", (int)v.size());
        for (const auto& el : v){
            printf("1/%d = 1/%lld + 1/%lld\n", k, el.first, el.second);
        }
        cin >> k;
    }
}