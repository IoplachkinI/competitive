#include<bits/stdc++.h>

using namespace std;

const int MAXID = 5, MAXREM = 30001;

vector<vector<long long>> memo (MAXID, vector<long long> (MAXREM));
vector<int> coins {1, 5, 10, 25, 50};

long long rec(int id, int rem){
    if (rem == 0) return 1;
    if (id == MAXID || rem < 0) return 0;
    long long& ans = memo[id][rem];
    if (ans != -1) return ans;
    return ans = rec(id, rem-coins[id]) + rec(id+1, rem);
}

int main(){
    for (auto& a : memo) for (auto& b : a)
        b = -1;
    while (true){
        int n;
        cin >> n;
        if (cin.eof()) break;
        long long ans = rec (0, n);
        if (ans == 1) printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %lld ways to produce %d cents change.\n", ans, n);
    }
}