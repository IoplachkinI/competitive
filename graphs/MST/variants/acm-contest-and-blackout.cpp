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
        if (v == u) return;
        if (rank[u] > rank[v]) p[v] = u;
        else if (rank[v] > rank[u]) p[u] = v;
        else {
            p[v] = u;
            rank[u]++;
        }
    }

};


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        n++;
        vector<vector<int>> edgelist;
        for (int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edgelist.push_back({w, min(u, v), max(u, v)});
        }
        sort(edgelist.begin(), edgelist.end());
        Ufds ufds(n);
        long long cost1 = 0;
        vector<vector<int>> path;
        for (const auto& a : edgelist){
            if (ufds.sameroot(a[1], a[2])) continue;
            ufds.join(a[1], a[2]);
            path.push_back(a);
            cost1 += a[0];
        }
        long long cost2 = numeric_limits<long long>::max();
        for (const auto& ban : path){
            Ufds ufds2(n);
            long long curcost = 0;
            int cnt = 0;
            for (const auto& a : edgelist){
                if (ufds2.sameroot(a[1], a[2]) || a == ban) continue;
                ufds2.join(a[1], a[2]);
                curcost += a[0];
                cnt++;
            }
            if (cnt != (int)path.size()) continue;
            cost2 = min(curcost, cost2);
        }

        printf("%lld %lld\n", cost1, cost2);
    }
}
