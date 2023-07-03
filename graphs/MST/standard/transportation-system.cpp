#include <bits/stdc++.h>


using namespace std;


class Ufds {
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


vector<vector<int>> adjlist;
vector<pair<double, pair<int, int>>> edgelist;
vector<int> visited;
void dfs(int u, double r){
    visited[u] = 1;
    for (const auto& a : adjlist[u]){
        if (visited[a]) continue;
        dfs(a, r);
    }
}


int main(){
    int t;
    cin >> t;
    for (int k = 0; k < t; k++){
        int n;
        double r;
        cin >> n >> r;
        vector<pair<double, double>> coords;
        edgelist.clear();
        visited.assign(n, 0);
        adjlist.assign(n, {});
        for (int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            coords.push_back({x, y});
        }
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
            double d = sqrt(pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2));
            edgelist.push_back({d, {i, j}});
            if (d <= r) {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
        int states = 0;
        sort(edgelist.begin(), edgelist.end());

        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            dfs(i, r);
            states++;
        }

        Ufds ufds(n);
        double road = 0.0, railroad = 0.0;
        for (int i = 0; i < (int) edgelist.size(); i++){
            if (ufds.sameroot(edgelist[i].second.first, edgelist[i].second.second)) continue;
            ufds.join(edgelist[i].second.first, edgelist[i].second.second);
            if (edgelist[i].first > r) railroad += edgelist[i].first;
            else road += edgelist[i].first;
        }
        int _road = round(road);
        int _railroad = round (railroad);
        printf("Case #%d: %d %d %d\n", k+1, states, _road, _railroad);
    }
}

