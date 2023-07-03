#include <bits/stdc++.h>


using namespace std;


int main(){
    while (true) {
        int v;
        cin >> v;
        if (!v) break;

        vector<vector<int>> adjlist (v+1, vector<int>());

        while (true) {
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
            if (a == 0) break;
        }

        bool good = true;
        queue<int> q;
        vector<int> colors;
        colors.assign(v+1, -1);
        q.push(1);
        colors[1] = 0;
        
        while (!q.empty() && good) {
            int cur = q.front();
            q.pop();

            for (const auto& next : adjlist[cur]) {
                if (colors[next] == -1) {
                    colors[next] = 1 - colors[cur];
                    q.push(next);
                }

                else if (colors[next] == colors[cur]) {
                    good = false;
                    break;
                }
            }
        }

        if (good) cout << "YES\n";
        else cout << "NO\n";

    }
}
