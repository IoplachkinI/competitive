#include <bits/stdc++.h>


using namespace std;


class Ufds{
private:
    vector<int> rank, p;
public:
    Ufds(int n){
        rank.assign(n, 0);
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int findroot(int u){
        if (p[u] == u) return u;
        return p[u] = findroot(p[u]);
    }

    bool sameroot(int u, int v){
        return findroot(u) == findroot(v);
    }

    void join(int u, int v){
        u = findroot(u);
        v = findroot(v);
        if (u == v) return;
        if (rank[u] > rank[v]) p[v] = u;
        else if (rank[v] > rank[u]) p[u] = v;
        else {
            p[v] = u;
            rank[u]++;
        }
    }
};

vector<vector<pair<int, int>>> adjlist;
vector<int> visited;
int ans;
void dfs(int u, int v, int maxval){
    visited[u] = 1;
    if (u == v){
        ans = maxval;
        return;
    }
    for (const auto& a: adjlist[u]){
        if (visited[a.first]) continue;
        dfs(a.first, v, max(maxval, a.second));
    }
}

int main(){
    int cnt = 0;
    while (true){
        cnt++;
        int c, s, q;
        cin >> c >> s >> q;
        if (!c) break;
        Ufds ufds (c+1);
        vector<vector<int>> edgelist(s, vector<int>());
        adjlist.assign(c+1, vector<pair<int, int>>());
        visited.assign(c+1, 0);
        for (int i = 0; i < s; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edgelist[i] = {w, u, v};
        }
        sort(edgelist.begin(), edgelist.end());
        for (const auto& a : edgelist){
            if (ufds.sameroot(a[1], a[2])) continue;
            ufds.join(a[1], a[2]);
            adjlist[a[1]].push_back({a[2], a[0]});
            adjlist[a[2]].push_back({a[1], a[0]});
        }
        if (cnt != 1) cout << "\n";
        printf("Case #%d\n", cnt);
        for (int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v;
            ans = 0;
            visited.assign(c+1, 0);
            dfs(u, v, 0);
            if (!ans) cout << "no path\n";
            else cout << ans << '\n';
        }
    }
}
