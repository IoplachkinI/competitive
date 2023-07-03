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
        if (sameroot(u, v)) return;
        u = findroot(u);
        v = findroot(v);
        if (rank[u] > v) p[v] = u;
        else if (rank[v] > u) p[u] = v;
        else {
            p[u] = v;
            rank[v]++;
        }
    }
};


int main(){
    int t;
    cin >> t;
    bool first = true;
    while (t--){
        int n;
        cin >> n;
        vector<pair<double, double>> v;
        vector<pair<double, pair<int, int>>> edgeList;
        for (int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++){
            double d = sqrt(powf((v[i].first - v[j].first), 2) + powf((v[i].second - v[j].second), 2));
            edgeList.push_back({d, {i, j}});
        }
        sort(edgeList.begin(), edgeList.end());
        Ufds ufds(n);
        long double cost = 0;
        for (const auto& a : edgeList){
            if (ufds.sameroot(a.second.first, a.second.second)) continue;
            ufds.join(a.second.first, a.second.second);
            cost += a.first;
        }
        if (!first) cout << "\n";
        first = false;
        printf("%.2Lf\n", cost);
    }
}
