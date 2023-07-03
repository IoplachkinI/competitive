#include <bits/stdc++.h>


using namespace std;


class Ufds{
private:
    vector<int> rank, p;
public:
    Ufds(int n){
        rank.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++){
            rank[i] = 0;
            p[i] = i;
        }
    }
    int findroot(int u){
        if (p[u] == u){
            return u;
        }
        return p[u] = findroot(p[u]);
    }
    bool sameroot(int u, int v){
        return findroot(u) == findroot(v);
    }
    void join(int u, int v){
        if (sameroot(u, v)) return;
        u = findroot(u); //ЭТО НЕ ЗАБЫВАТЬ
        v = findroot(v);
        if (rank[u] > rank[v]) p[v] = u;
        else if (rank[v] > rank[u]) p[u] = v;
        else{
            p[v] = u;
            rank[u]++;
        }
    }
};


int main(){
    bool first = true;
    while (true){
        vector<vector<int>> edgeList; // {w, u, v}
        int n;
        cin >> n;
        if (cin.eof()) break;
        long long cost1 = 0;
        for (int i = 0; i < n-1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            cost1 += (long long) w;
        }

        int k;
        cin >> k;
        for (int i = 0; i < k; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edgeList.push_back({w, u, v});
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edgeList.push_back({w, u, v});
        }
        sort(edgeList.begin(), edgeList.end());
        long long cost2 = 0;
        Ufds ufds(n+1);
        for (const auto& a : edgeList){
            if (ufds.sameroot(a[1], a[2])) continue;
            ufds.join(a[1], a[2]);
            cost2 += a[0];
        }
        if (!first) cout << "\n";
        first = false;
        cout << cost1 << "\n" << cost2 << endl;
    }
    return 0;
}
