#include <bits/stdc++.h>


using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--){
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adjlist(v, vector<int>());
        for (int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        bool good = true;
        int total = 0;
        vector<int> colored;
        vector<int> visited;
        visited.assign(v, 0);

        for (int i = 0; i < v && good; i++){
            if (visited[i]) continue;
            colored.assign(v, -1);
            queue<int> q;
            q.push(i);
            colored[i] = 0;
            
            while (!q.empty() && good){
                int cur = q.front();
                q.pop();
                if (visited[cur]) continue;
                visited[cur] = 1;

                for (int j = 0; j < (int)adjlist[cur].size() && good; j++){
                    int next = adjlist[cur][j];
                    
                    if (colored[next] == -1) {
                        colored[next] = 1 - colored[cur];
                        q.push(next);
                    }
                    
                    else if (colored[next] == colored[cur]) good = false;
                }
            }
            
            if (!good) good = false;
            else {
                int cnt1 = 0, cnt0 = 0;
                for (const auto& a : colored) {
                    if (a == 1) cnt1++;
                    else if (a == 0) cnt0++;
                }
                int cntmin = min(cnt1, cnt0);
                if (cntmin == 0) cntmin = 1;
                total += cntmin;
            }
            //for (const auto&a : colored) cout << a << ' ';
            //cout << '\n';
        }
        if (total == 0) total = -1;
        cout << total << '\n';
    }
}
