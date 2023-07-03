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
        else{
            p[v] = u;
            rank[u]++;
        }
    }

};


vector<vector<int>> adjlist;
vector<int> visited;
void dfs(int u){
    visited[u] = 1;
    for (const auto& a : adjlist[u]){
        if (visited[a]) continue;
        dfs(a);
    }
}

bool allVisited(){
    bool ans = true;
    for (int i = 0; i < (int)visited.size(); i++) {
        if (!visited[i]) {
            ans = false;
            break;
        }
    }
    return ans;
}


int main(){
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++){
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edgelist(e);
        adjlist.assign(v, {});
        visited.assign(v, 0);
        Ufds ufds(v);
        for (int i = 0; i < e; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            edgelist[i] = {w, u, v};
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        dfs(0);
        if (!allVisited()) {
            printf("Case #%d : No way\n", k);
            continue;
        }
        sort(edgelist.begin(), edgelist.end());
        set<vector<int>> path;
        long long cost1 = 0, cost2 = numeric_limits<long long>::max();
        for (const auto& a : edgelist){
            if (ufds.sameroot(a[1], a[2])) continue;
            ufds.join(a[1], a[2]);
            path.insert(a);
            cost1 += a[0];
        }

        bool secondway = false;
        for (const auto& banned : path){
            long long curcost = 0;
            Ufds ufds(v);
            int nodes = 0;
            for (const auto& a : edgelist){
                if (ufds.sameroot(a[1], a[2]) || a == banned) continue;
                ufds.join(a[1], a[2]);
                curcost += a[0];
                nodes++;
            }
            if (nodes >= (int)path.size()) {
                cost2 = min(cost2, curcost);
                secondway = true;
            }
        }
        if (!secondway) printf("Case #%d : No second way\n", k);
        else printf("Case #%d : %lld\n", k, cost2);
    }
}
