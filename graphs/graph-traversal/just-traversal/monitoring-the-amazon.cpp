#include <bits/stdc++.h>

using namespace std;


int n, stationx, stationy;
const int MAXN = 1001;
const int XBOUND = 20, YBOUND = 20; // -20 <= x,y <= 20

vector<vector<int>> closest(MAXN, vector<int>(2));
vector<vector<int>> coords(MAXN, vector<int>(2));
vector<int> visited(MAXN);

float dist (int i, int j){
    if (i < 0 || j < 0) return FLT_MAX;
    return sqrt(pow(coords[i][0] - coords[j][0], 2) + pow(coords[i][1] - coords[j][1], 2));
}

void dfs(int cur){
    if (cur < 0 || cur > n || visited[cur]) return;
    visited[cur] = 1;
    dfs(closest[cur][0]);
    dfs(closest[cur][1]);
}

int main(){
    while (true){
        cin >> n;
        if (!n) break;
        cin >> coords[0][0] >> coords[0][1];
        for (auto& a : closest) a = {-1, -1};
        for (auto& a : visited) a = 0;

        for (int i = 1; i < n; i++){
            cin >> coords[i][0] >> coords[i][1];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                if (dist(j, i) < dist(j, closest[j][0])) closest[j][0] = i;
                else if (dist(j, i) < dist(j, closest[j][1])) closest[j][1] = i;
            }
        
        dfs(0);
        bool good = true;
        for (int i = 0; i < n; i++) if (!visited[i]) good = false;

        if (good) cout << "All stations are reachable.\n";
        else cout << "There are stations that are unreachable.\n";

    }

}