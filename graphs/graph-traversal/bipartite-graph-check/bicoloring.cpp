#include <bits/stdc++.h>


using namespace std;


int main(){
    while (true){
        int n;
        cin >> n;
        if (!n) break;

        vector<vector<int>> adjlist(n);
        vector<int> colors;
        colors.assign(n, -1);

        int l;
        cin >> l;
        for (int i = 0; i < l; i++){
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        queue<int> q;
        q.push(0);
        colors[0] = 1;
        bool good = true;
        while (!q.empty() && good){
            int cur = q.front();
            q.pop();
            for (int i = 0; i < (int)adjlist[cur].size() && good; i++){
                int next = adjlist[cur][i];
                if (colors[next] == -1) {
                    colors[next] = 1-colors[cur];
                    q.push(next);
                }
                else if (colors[next] == colors[cur]) good = false;
            }
        }

        if (!good) cout << "NOT BICOLORABLE.\n";
        else cout << "BICOLORABLE.\n";
    }
}
