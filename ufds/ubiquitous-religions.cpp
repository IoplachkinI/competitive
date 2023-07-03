#include <bits/stdc++.h>

using namespace std;

//#define o cout

class ufds{
private:
    vector<int> rank, p;

public:
    ufds(int n){
        rank.assign(n, 0);
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int findRoot(int a){
        set<int> s;
        while (p[a] != a){
            s.insert(a);
            a = p[a];
        }
        for (const auto& el : s) p[el] = a;
        return a;
    }
    bool sameRoot(int a, int b){
        return findRoot(a) == findRoot(b);
    }
    void join(int a, int b){
        if (sameRoot(a, b)) return;

        if (rank[a] > rank[b]) p[b] = a;
        else if (rank[b] > rank[a]) p[a] = b;
        else {
            p[a] = b;
            rank[b]++;
        }
    }
    int sets(){
        set <int> s;
        for (const auto& el : p) s.insert(findRoot(el));
        return s.size();
    }

};


int main(){
    int n, m, c = 0;
    cin >> n >> m;
    while (n || m){
        c++;
        ufds u (n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            u.join(u.findRoot(a - 1), u.findRoot(b - 1));
        }
        cout << "Case " << c << ": ";
        cout << u.sets() << '\n';
        cin >> n >> m;
    }
}