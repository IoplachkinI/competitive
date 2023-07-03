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
            p[u] = v;
            rank[v]++;
        }
    }
};


vector<vector<pair<long double, int>>> adjlist;
vector<int> visited;
long double MaxLen;
void dfs(int u, int v, long double maxlen){
    visited[u] = 1;
    if (u == v) {
        MaxLen = maxlen;
        return;
    }
    for (const auto& a : adjlist[u]){
        if (visited[a.second]) continue;
        dfs(a.second, v, max(maxlen, a.first));
    }
}


int main(){
    int cnt = 0;
    while (true){
        MaxLen = 0.0;
        cnt++;
        int n;
        cin >> n;
        if (!n) break;
        vector<pair<long double, long double>> coords;
        vector<pair<long double, pair<int, int>>> edgelist;
        for (int i = 0; i < n; i++){
            long double x, y;
            cin >> x >> y;
            coords.push_back({x, y});
        }

        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++){
            long double d = sqrt(powf(coords[i].first - coords[j].first, 2) + powf(coords[i].second - coords[j].second, 2));
            edgelist.push_back({d, {i, j}});
        }

        Ufds ufds(n);
        sort(edgelist.begin(), edgelist.end());
        adjlist.assign(n, vector<pair<long double, int>> ());
        visited.assign(n, 0);
        for (const auto& a : edgelist){
            if (ufds.sameroot(a.second.first, a.second.second)) continue;
            ufds.join(a.second.first, a.second.second);
            adjlist[a.second.first].push_back({a.first, a.second.second});
            adjlist[a.second.second].push_back({a.first, a.second.first});
        }

        dfs(0, 1, 0.0);

        printf("Scenario #%d\n", cnt);
        printf("Frog Distance = %.3Lf\n\n", MaxLen);
    }
}
