#include <bits/stdc++.h>

using namespace std;


const int MAXN = 101;
int n, m;
vector<vector<int>> adjlist(MAXN);
vector<int> visited(MAXN);
vector<int> sorted;


void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = 1;
    for (int i = 0; i < adjlist[cur].size(); i++)
        dfs(adjlist[cur][i]);
    sorted.push_back(cur);
}


int main(){
    while (true){
        cin >> n >> m;
        if (!n) break;

        for (auto& a : adjlist) a = {};
        for (auto& a : visited) a = 0;
        sorted.clear();

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
        }
        
        for (int i = 1; i <= n; i++)
            if (!visited[i]) dfs(i);
        
        for (auto it = sorted.rbegin(); it < sorted.rend(); it++){
            if (it != sorted.rbegin()) cout << ' ';
            cout << *it;
        }
        cout << '\n';
    }
}