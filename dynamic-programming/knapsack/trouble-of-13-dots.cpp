#include <bits/stdc++.h>

using namespace std;

int m, n;
const int MAXN = 101, MAXM = 10001;
vector<int> p, f;
vector<vector<int>> memo (MAXN, vector<int>(MAXM));

int rec(int id, int remm){
    if (id == n || remm == 0) {
        if (m > 1800 && m <= 2000 && m + 200 - remm <= 2000 && m + 200 - remm > m) 
            return INT32_MIN; 
        return 0;
    }
    int& ans = memo[id][remm];
    if (ans != -1) return ans;
    if (p[id] > remm) return ans = rec(id+1, remm);
    return ans = max(
        rec(id+1, remm),
        rec(id+1, remm-p[id]) + f[id]
    );
}

int main(){
    while (true){
        cin >> m >> n;
        if (cin.eof()) break;

        for (auto& a : memo)
            for (auto& b : a)
                b = -1;

        p.resize(n), f.resize(n);
        for (int i = 0; i < n; i++){
            cin >> p[i] >> f[i];
        }

        int ans;
        if (m > 1800)
            ans = rec(0, m + 200);
        else
            ans = rec(0, m);
        ans = max(ans, 0);
        cout << ans << "\n";
    }
}