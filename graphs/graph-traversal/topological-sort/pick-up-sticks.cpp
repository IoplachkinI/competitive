#include <bits/stdc++.h>

using namespace std;


const int MAXN = 1000001;
int n, m;
vector<vector<int>> adjlist(MAXN);
vector<int> visited(MAXN);
vector<int> sorted(MAXN);
vector<int> curvisited(MAXN);


bool cycle;
void dfs(int cur){
    if (visited[cur]) {
        if (curvisited[cur]) cycle = true;
        return;
    }
    visited[cur] = 1;
    curvisited[cur] = 1;
    for (const auto& a : adjlist[cur])
        dfs(a);
    curvisited[cur] = 0;
    sorted.push_back(cur);
}


int main(){
    while (true){
        cin >> n >> m;
        if (!n) break;

        for (int i = 0; i <= n; i++) {
            visited[i] = 0;
            curvisited[i] = 0;
            adjlist[i] = {};
        }
        sorted.clear();

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
        }

        cycle = false;
        for (int i = 1; i <= n && !cycle; i++)
            if (!visited[i]) dfs(i);

        if (cycle) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        for (auto it = sorted.rbegin(); it < sorted.rend(); it++)
            cout << *it << '\n';

    }
}