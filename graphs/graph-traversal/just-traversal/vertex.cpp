#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adjList;
vector<int> visited;

void dfs(int cur){
    for (int i = 1; i <= adjList[cur][0]; i++){
        if (visited[adjList[cur][i]]) continue;
        visited[adjList[cur][i]] = 1;
        dfs(adjList[cur][i]);
    }
}

int main(){
    while (true) {
        cin >> n;
        if (!n) break;
        adjList.assign(n+1, vector<int>());
        for (int i = 0; i < n+1; i++) adjList[i].assign(n+1, 0); 
        //adjList[i][0] показывает, сколько ребер выходит из i, далее идут вершины - концы этих ребер


        while (true){
            int start;
            cin >> start;
            if (!start) break;
            while (true) {
                int end;
                cin >> end;
                if (!end) break;
                adjList[start][adjList[start][0]+1] = end;
                adjList[start][0]++;
            }
        }

        /*for (auto& a : adjList){
            for (auto&b : a) {
                cout << b << ' ';
            }
            cout << '\n';
        }*/      

        int q;
        cin >> q;
        for (int i = 0; i < q; i++){
            visited.assign(n+1, 0);
            int start;
            cin >> start;
            dfs(start);
            int cnt = 0;
            for (int i = 1; i < n+1; i++) cnt += !visited[i];
            cout << cnt;
            for (int i = 1; i < n+1; i++) if (!visited[i]) cout << ' ' << i;
            cout << '\n';
        }

    }
}