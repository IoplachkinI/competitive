#include <bits/stdc++.h>


using namespace std;


int dfsroot, numcnt;
vector<vector<int>> adjlist;
vector<int> dfsnum, dfslow, visited;
vector<int> s;


void dfs(int u) {
    dfsnum[u] = dfslow[u] = numcnt++;
    visited[u] = 1;
    s.push_back(u);
    
    for (const auto& v : adjlist[u]){
        if (!visited[v])
            dfs(v);
        dfslow[u] = min(dfslow[u], dfslow[v]);
    }

    if (dfsnum[u] == dfslow[u]) {
        while (true){
            
        }
    }
}


int main(){
    int n;
    cin >> n;
    adjlist.assign(n, vector<int>());
    dfsnum.assign(n, 0);
    dfslow.assign(n, 0);
    visited.assign(n, 0);
    s.clear();
    dfsroot = 0, numcnt = 0;
    while (true){
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        if (u == -1) break;
    }

            
}
