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


int main(){
    while (true){
        int n, m;
        cin >> n >> m;
        if (!n && !m) break;
        Ufds ufds (n);
        vector<vector<int>> edgelist(m, vector<int>());
        for (int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edgelist[i] = {w, u, v};
        }

        sort(edgelist.begin(), edgelist.end());
        bool forest = true;
        for (const auto& a : edgelist){
            if (ufds.sameroot(a[1], a[2])) {
                if (!forest) cout << ' ';
                cout << a[0];
                forest = false;
            };
            ufds.join(a[1], a[2]);
        }
        if (forest) cout << "forest";
        cout << "\n";

    }
}
