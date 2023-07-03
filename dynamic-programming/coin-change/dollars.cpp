#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXM = 11, MAXREM = 30001;
vector<int> money {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
vector<vector<long long>> memo (MAXM, vector<long long>(MAXREM));

long long rec(int id, int rem){
    if (rem == 0) return 1;
    if (id == MAXM || rem < 0) return 0;
    long long& ans = memo[id][rem];
    if (ans != -1) return ans;
    return ans = rec(id, rem-money[id]) + rec(id+1, rem);
}

int main(){
    for (auto& a : memo) for (auto& b : a)
        b = -1;
    while (true){
        float in;
        cin >> in;
        if (in < 0.000001) break;
        n = round(in * 100.0);
        long long ans = rec(0, n);
        printf("%6.2f%17lld\n", in, ans);
    }
}