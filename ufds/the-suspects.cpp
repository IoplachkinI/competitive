#include <bits/stdc++.h>

using namespace std;

#define o cout

class ufds{
private:
    vector<int> rank, p;
public:
    ufds(int n){
        rank.assign(n, 0);
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int findRoot(int a) {
        vector<int> prev;
        while (p[a] != a){
            prev.push_back(a);
            a = p[a];
        }
        for (const auto& el : prev) p[el] = a;
        return a;
    }
    bool sameRoot(int a, int b){
        return findRoot(a) == findRoot(b);
    }
    void join(int a, int b){
        if (rank[a] > rank[b]) p[b] = a;
        else if (rank[b] > rank[a]) p[a] = b;
        else {
            p[a] = b;
            rank[b]++;
        }
    }
    int countSet(int a){
        int root = findRoot(a);
        int cnt = 0;
        for (int i = 0; i < p.size(); i++){
            cnt += (findRoot(i) == root);
        }
        return cnt;
    }

};

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0){
        ufds u (n);
        for (int i = 0; i < m; i++){
            int k;
            cin >> k;
            int a, b;
            cin >> a;
            for (int j = 1; j < k; j++) {
                cin >> b;
                u.join(u.findRoot(a), u.findRoot(b));
                a = b;
            }
        }
        o << u.countSet(0) <<'\n';
        cin >> n >> m;
    }
    //o.close();
}