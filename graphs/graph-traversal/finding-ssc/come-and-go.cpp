#include <bits/stdc++.h>


using namespace std;


int numcnt;
int good;
vector<vector<int>> adjlist;
vector<int> dfsnum, dfslow, S, visited, currentssc;


void dfs(int u){
    dfsnum[u] = dfslow[u] = numcnt++;
    visited[u] = currentssc[u] = 1;
    S.push_back(u);

    for (const auto& v : adjlist[u]){
        if (!visited[v])
            dfs(v);
        if (currentssc[v])
            dfslow[u] = min(dfslow[u], dfslow[v]);
    }

    if (dfsnum[u] == dfslow[u]){
        int cnt = 0;
        while (true){
            int v = S.back();
            cnt++;
            S.pop_back();
            currentssc[v] = 0;
            //cout << v << '\n';
            if (u == v) break;
        }
        if (cnt == adjlist.size()-1) good = 1;
        //cout << '\n';
    }
}


int main(){
    while (true){
        int n, m;
        cin >> n >> m;
        if (!n) break;

        n++;
        numcnt = 0;
        good = 0;
        adjlist.assign(n, vector<int>());
        dfsnum.assign(n, 0);
        dfslow = visited = currentssc = dfsnum;

        while (m--){
            int v, w, p;
            cin >> v >> w >> p;
            adjlist[v].push_back(w);
            if (p == 2) adjlist[w].push_back(v);
        }

        for (int i = 1; i < n; i++)
            if (!visited[i]) dfs(i);

        cout << good << '\n';
    }
}
