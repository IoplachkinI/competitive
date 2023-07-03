#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101, MAXREM = 20001;
int n;

vector<int> money(MAXN);
vector<vector<int>> memo (MAXN, vector<int>(MAXREM));

int rec1(int id, int rem){
    if (rem <= 0) return rem;
    if (id == n) return INT32_MIN / 2;
    int& ans = memo[id][rem];
    if (ans != -1) return ans;
    return ans = max(
        rec1(id+1, rem-money[id]),
        rec1(id+1, rem)
    );
}

int rec2(int id, int rem){
    if (rem == 0) return 0;
    if (rem < 0 || id == n) return INT32_MAX / 2;
    int& ans = memo[id][rem];
    if (ans != -1) return ans;
    return ans = min(
        rec2(id+1, rem),
        rec2(id+1, rem-money[id]) + 1
    );
}


int main(){
    int t;
    cin >> t;
    while (t--){
        int num;
        cin >> num >> n;
        for (int i = 0; i < n; i++)
            cin >> money[i];

        for (auto& a : memo) for (auto& b : a)
            b = -1;
        
        int k = num - rec1(0, num);
        for (auto& a : memo) for (auto& b : a)
            b = -1;
        int ans = rec2(0, k);
        cout << k << " " << ans << "\n";
    }
}