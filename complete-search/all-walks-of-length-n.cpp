#include <bits/stdc++.h>

using namespace std;

int n, l;
bool good;
vector<vector<int>> v (10, vector<int> (10));
vector<int> visited (10);

void rec(int node, int dist, vector<int>& path){
    path[0]++;
    path[path[0]] = node + 1;
    
    if (dist == l && !visited[node]) {
        good = true;
        cout << "(" << path[1];
        for (int i = 2; i <= path[0]; i++) cout << "," << path[i];
        cout << ")\n";
    }

    for (int i = 0; i < n && !visited[node]; i++) 
        if (v[node][i] && i != node) {
            visited[node] = true;
            rec (i, dist + 1, path);
            visited[node] = false;
        }

    path[path[0]] = 0;
    path[0]--;
}

int main(){
    int cnt = 0;
    while (true){
        good = false;
        n = -1, l = - 1;
        cin >> n;
        if (n == -1) break;
        else if (n == -9999) cin >> n;
        cin >> l;
        
        if (cnt) cout << "\n";
        cnt++;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }

        vector<int> tmp;
        tmp.assign(n + 1, 0);
        rec(0, 0, tmp);
        if (!good) cout << "no walk of length " << l << "\n";
    }
}