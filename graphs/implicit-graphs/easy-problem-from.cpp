#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    while (!cin.eof()){
        map<int, vector<int>> occ;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            if (!occ.count(a)) occ[a] = vector<int> ();
            occ[a].push_back(i);
        }
        for (int i = 0; i < m; i++){
            int k, v; 
            cin >> k >> v;
            if (!occ.count(v) || occ[v].size() < k) cout << "0\n";
            else cout << occ[v][k-1] + 1 << '\n';

        }
        cin >> n >> m;
    }
}