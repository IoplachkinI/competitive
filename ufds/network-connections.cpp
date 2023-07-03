#include <bits/stdc++.h>

using namespace std;

class ufds{
private:
    vector<int> rank, p;
public:
    ufds(int n){
        rank.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0; p[i] = i;
        }
    }
    int findRoot(int a){
        return (p[a] == a) ? a : findRoot(p[a]);
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
};

int main(){
    int c;
    cin >> c;
    while (c--){
        int n; 
        cin >> n;
        cin.ignore(100, '\n');
        int succ = 0, unsucc = 0;
        ufds u (n);
        string str;
        getline(cin, str);

        while (str.size() > 0){
            stringstream s(str);
            char action;
            int a, b;
            s >> action >> a >> b;
            if (action == 'c') u.join(u.findRoot(a - 1), u.findRoot(b - 1));
            else {
                succ += u.sameRoot(a - 1, b - 1);
                unsucc += !u.sameRoot(a - 1, b - 1);
            }
            getline(cin, str);
        }

        printf("%d,%d\n", succ, unsucc);
        if (c) printf("\n");
    }
}