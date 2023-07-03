#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int n;
vector<vector<int>> adjlist (MAXN, vector<int>(MAXN+1));
vector<int> visited(MAXN);

void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = 1;
    for (int i = 1; i <= adjlist[cur][0]; i++)
        dfs(adjlist[cur][i]);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        char in;
        cin >> in;
        cin.ignore(100, '\n');
        n = in - 'A' + 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adjlist[i][j] = 0;
        for (int i = 0; i < n; i++) visited[i] = 0;
        while (true){
            string str;
            getline(cin, str);
            if (str.size() == 0) break;
            int a = str[0]-'A';
            int b = str[1]-'A';
            adjlist[a][0]++;
            adjlist[a][adjlist[a][0]] = b;
            adjlist[b][0]++;
            adjlist[b][adjlist[b][0]] = a;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            cnt++;
            dfs(i);
        }
        cout << cnt << '\n';
        if (t) cout << '\n';
    }
}