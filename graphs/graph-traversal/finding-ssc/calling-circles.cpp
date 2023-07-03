#include <bits/stdc++.h>


using namespace std;


int numcnt;
vector<vector<int>> adjlist;
vector<int> dfsnum, dfslow, visited, currentssc, S;
map <string, int> nametoind;
map <int, string> indtoname;


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

    if (dfslow[u] == dfsnum[u]){
        int flag = 0;
        while (true){
            int v = S.back();
            S.pop_back();
            currentssc[v] = 0;
            if (flag) cout << ", ";
            cout << indtoname[v];
            flag = 1;
            if (u == v) break;
        }
        cout << "\n";
    }
}


int main(){
    int _case = 0;
    while (true){
        _case++;
        int n, m;
        cin >> n >> m;
        if (!n) break;

        adjlist.assign(n, vector<int>());
        dfsnum.assign(n, 0);
        dfslow = visited = currentssc = dfsnum;
        S.clear();
        nametoind.clear();
        indtoname.clear();
        numcnt = 0;
        int ind = 0;

        while (m--){
            string a, b;
            cin >> a >> b;
            if (!nametoind.count(a)) 
                nametoind[a] = ind++;
            if (!nametoind.count(b))
                nametoind[b] = ind++;
            int u = nametoind[a];
            int v = nametoind[b];
            indtoname[u] = a;
            indtoname[v] = b;
            adjlist[u].push_back(v);
        }

        if (_case-1) cout << '\n';
        cout << "Calling circles for data set " << _case << ":\n";
        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            dfs(i);
        }

    }
}
