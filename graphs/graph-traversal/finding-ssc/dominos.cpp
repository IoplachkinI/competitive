#include <bits/stdc++.h>


using namespace std;


int numcnt, ssccnt;
vector<vector<int>> adjlist;
vector<vector<int>> reverseadjlist;
vector<int> dfslow, dfsnum, S, visited, currentssc;


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
        ssccnt++;
        vector<int> s;
        while (true){
            int v = S.back();
            S.pop_back();
            currentssc[v] = 0;
            s.push_back(v);
            if (v == u) break;
        }
        bool hasIncomingEdge = false;
        for (const auto& a : s){
            //cout << a << '\n';
            for (const auto& b : reverseadjlist[a])
                if (!count(s.begin(), s.end(), b))
                    hasIncomingEdge = true;
        }
        //cout << '\n';
        
        if (hasIncomingEdge) ssccnt--;
    }
}


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        n++;
        adjlist.assign(n, vector<int>());
        reverseadjlist = adjlist;
        dfslow.assign(n, 0);
        numcnt = 0;
        ssccnt = 0;
        dfsnum = visited = currentssc = dfslow;
        S.clear();

        while (m--){
            int u, v;
            cin >> u >> v;
            adjlist[u].push_back(v);
            reverseadjlist[v].push_back(u);
        }
        
        for (int i = 1; i < n; i++){
            if (!visited[i])
                dfs(i);
        }

        /*
        for (int i = 1; i < n; i++){
            cout << i << ": ";
            for (const auto& a : adjlist[i]) cout << a << ' ';
            cout << '\n';
        }
        */

        /*
        int ssc = 0;
        for (int i = 1; i < n; i++) if (reverseadjlist[i].size() == 0) ssc++;
        if (ssc == 0) ssc = 1;
        */

        if (ssccnt == 0) ssccnt = 1;
        cout << ssccnt << '\n';
    }
}
