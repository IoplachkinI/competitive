#include <bits/stdc++.h>


using namespace std;


class Ufds{
private:
    vector<int> rank, p;
public:
    Ufds(int n){
        rank.assign(n, 0);
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
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


int main(){
    while (true){
        int m, n;
        cin >> m >> n;
        if (!m && !n) break;
        Ufds ufds(m);
        long long cost1 = 0, cost2 = 0;
        vector<vector<int>> edgelist (n, vector<int>());
        for (int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            edgelist[i] = {z, x, y};
            cost1 += z;
        }
        sort(edgelist.begin(), edgelist.end());
        for (const auto& a : edgelist){
            if (ufds.sameroot(a[1], a[2])) continue;
            ufds.join(a[1], a[2]);
            cost2 += a[0];
        }
        cout << cost1 - cost2 << "\n";

    }
    return 0;
}
