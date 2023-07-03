#include <bits/stdc++.h>

using namespace std;

int MAXVAL = 62;
int n, back;

typedef unsigned long long ull;

vector<vector<pair<ull, ull>>> memo(MAXVAL, vector<pair<ull, ull>> (MAXVAL));

pair<ull, ull> rec(int n){
    if (n <= 0) return {0, 1};
    if (n == 1) return {1, 1};

    auto& ans = memo[n][back];
    if (ans.first != -1) {
        return ans;
    }

    ull sum = 0;
    ull cnt = 1;
    for (int i = 1; i <= back; i++){
        auto cur = rec(n-i);
        sum += cur.first;
        cnt += cur.second;
    }
    
    return ans = {sum, cnt};
}

int main(){
    int _case = 0;
    for (auto& a : memo) for (auto& b : a) b = {-1, 0};
    while (true){
        _case++;
        cin >> n >> back;
        if (n >= MAXVAL || back >= MAXVAL-1) break;
        printf("Case %d: %llu\n", _case, rec(n).second);
    }
}