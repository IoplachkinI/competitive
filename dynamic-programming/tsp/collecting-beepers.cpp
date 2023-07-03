#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX_N = 11;
vector<int> x(MAX_N), y(MAX_N);
vector<vector<int>> dist (MAX_N, vector<int> (MAX_N));
vector<vector<int>> memo(MAX_N, vector<int>((1 << MAX_N) - 1));

int rec(int pos, int mask){
    if (mask == (1 << (n+1)) - 1) return dist[0][pos];
    int& ans = memo[pos][mask];
    if (ans != -1) return ans;
    int tmp = INT32_MAX;
    for (int i = 0; i <= n; i++){
        if (mask & (1 << i)) continue;
        int cur = rec(i, mask | (1 << i));
        tmp = min(tmp, cur + dist[pos][i]);
    }
    return ans = tmp;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int max_x, max_y;
        cin >> max_x >> max_y;
        cin >> x[0] >> y[0];
        cin >> n;

        for (auto& a : memo) for (auto& b : a)
            b = -1;

        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];

        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
            dist[i][j] = dist[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        
        int ans = rec(0, 1);
        printf("The shortest path has length %d\n", ans);
    }
}