#include <bits/stdc++.h>

using namespace std;

int n, m, l;
const int MAXN = 10001;
vector<vector<int>> adjlist(MAXN);
vector<int> visited(MAXN);

int dfs(int cur){
    if (visited[cur]) return 0;
    visited[cur] = 1;
    int cnt = 1;
    for (int i = 0; i < adjlist[cur].size(); i++)
        cnt += dfs(adjlist[cur][i]);
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m >> l;
        for (int i = 0; i < n+1; i++) {
            adjlist[i] = {};
            visited[i] = 0;
        }
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
        }
        int cnt = 0;
        for (int i = 0; i < l; i++){
            int root;
            cin >> root;
            cnt += dfs(root);
        }
        cout << cnt << '\n';
    }
}