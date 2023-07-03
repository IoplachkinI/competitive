#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p, w;
vector<vector<int>> memo;

int rec(int id, int remw){
    if (id == n || remw == 0) return 0;
    int& ans = memo[id][remw];
    if (ans != -1) return ans;
    if (w[id] > remw) return ans = rec(id+1, remw);
    return ans = max(
        rec(id+1, remw),
        rec(id+1, remw-w[id]) + p[id]
    );
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        p.assign(n, 0);
        w.assign(n, 0);
        long long maxw = 0;
        for (int i = 0; i < n; i++){
            cin >> p[i] >> w[i];
            maxw += w[i];
        }
        memo.resize(n);
        for (int i = 0; i < n; i++)
            memo[i].assign(maxw+1, -1);

        int g;
        cin >> g;
        long long ans = 0;
        for (int i = 0; i < g; i++){
            int mw;
            cin >> mw;
            ans += rec(0, mw);
        }
        cout << ans << '\n';
    }
}