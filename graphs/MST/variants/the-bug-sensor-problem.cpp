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
        return p[u] = findroot(u);
    }

    bool sameroot(int u, int v){
        return findroot(u) == findroot(v);
    }

    void join(int u, int v){
        u = findroot(u);
        v = findroot(v);
        if (u == v) return;

    }
}


int main(){
    int w;
    cin >> w;
    while (w--){
        int n;
        cin >> n;
        vector<pair<double, pair<int, int>>> edgelist;
        vector<pair<int, int>> coords;
        while (true){
            int x, y;
            cin >> x;
            if (x < 0) break;
            cin >> y;
            coords.push_back({x, y});
        }

        for (int i = 0; i < (int)coords.size(); i++) for (int j = 0; j < (int)coords.size(); j++){
            long long x1 = coords[i].first, y1 = coords[i].second;
            long long x2 = coords[j].first, y2 = coords[j].second;
            double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            edgelist.push_back({d, {i, j}});
        }


    }
}
