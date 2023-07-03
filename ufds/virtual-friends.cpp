#include <bits/stdc++.h>

using namespace std;

#define o cout

class ufds{
private:
    vector<int> rank, p, size;
public:
    ufds(int n){
        rank.assign(n, 0);
        size.assign(n, 1);
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
        
        if (rank[a] > rank[b]) {
            p[b] = a;
            size[a] += size[b];
        }
        else if (rank[b] > rank[a]) {
            p[a] = b;
            size[b] += size[a];
        }
        else {
            p[a] = b;
            size[b] += size[a];
            rank[b]++;
        }
    }
    int getSetSize(int a){
        return size[findRoot(a)];
    }
};

int main(){
    //ofstream o;
    //o.open("out.txt");
    int t;
    cin >> t;
    while (t--){
        int f, ind = 0;
        cin >> f;
        map<string, int> m;
        ufds u (f * 2);
        while (f--){
            string a, b;
            cin >> a >> b;
            if (!m.count(a)){
                m[a] = ind;
                ind++;
            }
            if (!m.count(b)){
                m[b] = ind;
                ind++;
            }
            u.join(u.findRoot(m[a]), u.findRoot(m[b]));
            o << u.getSetSize(m[a]) << '\n';
        }
    }
    //o.close();
}