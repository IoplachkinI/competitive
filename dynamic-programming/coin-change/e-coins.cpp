#include <bits/stdc++.h>

using namespace std;

const int MAXM = 41, MAXXY = 301;
int m, s;
vector<int> con(MAXM), it(MAXM);

vector<vector<int>> memo (MAXXY, vector<int> (MAXXY));

int rec(int x, int y){
    int cur = (x * x + y * y);
    if (cur == s) {
        return 0;
    }
    if (cur > s) return INT32_MAX / 2;
    int& ans = memo[x][y];
    if (ans != -1) return ans;
    int tmp = INT32_MAX / 2;
    for (int i = 0; i < m; i++)
        tmp = min(tmp, rec(x + con[i], y + it[i]));
    return ans = tmp + 1;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        for (auto& a : memo) for (auto& b : a)
            b = -1;
        cin >> m >> s;
        s *= s;
        for (int i = 0; i < m; i++){
            cin >> con[i] >> it[i];
        }

        int ans = rec(0, 0);
        if (ans >= INT32_MAX / 2) cout << "not possible\n";
        else cout << ans << "\n";

    }
}