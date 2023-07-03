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
        int s, p;
        cin >> s >> p;
        vector<pair<double, double>> coords(p);
        vector<pair<double, pair<int, int>>> edgelist;
        for (int i = 0; i < p; i++){
            double x, y;
            cin >> x >> y;
            coords[i] = {x, y};
        }
        for (int i = 0; i < p; i++) for (int j = 0; j < p; j++){
            double d = sqrt(powf(coords[i].first - coords[j].first, 2) + powf(coords[i].second - coords[j].second, 2));
            edgelist.push_back({d, {i, j}});
        }

        sort(edgelist.begin(), edgelist.end());
        Ufds ufds (p);
        vector<double> weights;
        for (const auto& a : edgelist){
            if (ufds.sameroot(a.second.first, a.second.second)) continue;
            ufds.join(a.second.first, a.second.second);
            weights.push_back(a.first);
        }
        sort(weights.rbegin(), weights.rend());

        printf("%.2f\n", weights[s-1]);
    }
}
