#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> edges;
vector<vector<int>> nodes;
vector<int> used;
int maxdist;

void rec(int curnode, int dist){

    for (const auto& curedge : nodes[curnode]){
        if (used[curedge]) continue;
        used[curedge] = 1;
        int nextnode;
        if (edges[curedge].second == curnode) nextnode = edges[curedge].first;
        else nextnode = edges[curedge].second;
        rec(nextnode, dist + 1);
        used[curedge] = 0;
    }

    if (dist > maxdist) maxdist = dist;
}

int main(){
    cin >> n >> m;
    while(n || m){
        maxdist = 0;
        edges.assign(m, {0, 0});   
        nodes.assign(n, vector<int>());
        used.assign(m, 0);
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            edges[i] = {a, b};
            nodes[a].push_back(i);
            nodes[b].push_back(i);
        }
        
        /*for (int i = 0; i < m; i++){
            printf("%d: %d %d\n", i, edges[i].first, edges[i].second);
        }

        for (int i = 0; i < n; i++){
            printf("%d:", i);
            for (const auto& el : nodes[i]){
                printf(" %d", el);
            }
            printf("\n");
        }*/

        for (int i = 0; i < m; i++){
            rec(edges[i].first, 0);
            rec(edges[i].second, 0);
        }

        cout << maxdist << '\n';
        cin >> n >> m;
    }
}