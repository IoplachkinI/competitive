#include <bits/stdc++.h>


using namespace std;


class ufds {
private:
    vector<int> rank, p;
    set <int> path;
public:
    ufds(int n){
        rank.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++){
            rank[i] = 0;
            p[i] = i;
        }
    }
    int findroot(int n){
        if (p[n] == n) {
            for (const auto& a : path) p[a] = n;
            path.clear();
            return n;
        }
        path.insert(n);
        return findroot(p[n]);
    }
    bool sameroot(int a, int b){
        return findroot(a) == findroot(b);
    }
    void join(int a, int b){
        if (sameroot(a, b)) return;
        a = findroot(a);
        b = findroot(b);
        if (rank[a] > rank[b]) p[b] = a;
        else if (rank[b] > rank[a]) p[a] = b;
        else {
            p[a] = b;
            rank[b]++;
        }
    }
    void print(){
        cout << "p: ";
        for (const auto& a : p) cout << a << ' ';
        cout << '\n';
        cout << "rank: ";
        for (const auto& a : rank) cout << a << ' ';
        cout << "\n";
    }

};


int main(){
    ufds u (5);
    u.join(1, 2);
    u.join(0, 1);
    cout << u.sameroot(0, 3);

}
