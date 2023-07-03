#include <bits/stdc++.h>

using namespace std;


int r, c, sc;
int MAXR = 11, MAXC = 11;
vector<vector<char>> v (MAXR, vector<char> (MAXC));
vector<vector<char>> visited (MAXR, vector<char> (MAXC));


bool cycle = false;
int cnt;
int endr, endc;
void dfs(int curr, int curc){
    if (curr < 1 || curr > r || curc < 1 || curc > c) return;
    if (visited[curr][curc]) {
        cycle = true;
        endr = curr;
        endc = curc;
        return;
    }
    cnt++;
    visited[curr][curc] = 1;
    if (v[curr][curc] == 'N') dfs(curr-1, curc);
    else if (v[curr][curc] == 'E') dfs(curr, curc+1);
    else if (v[curr][curc] == 'S') dfs(curr+1, curc);
    else dfs(curr, curc-1);

}

int main(){
    while (true){
        cin >> r >> c >> sc;
        if (!r) break;

        cnt = 0; cycle = false;
        for (auto& a : v) for (auto& b : a) b = 'O';
        for (auto& a : visited) for (auto& b : a) b = 0;
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++){
            cin >> v[i][j];
        }

        dfs(1, sc);
        if (cycle) {
            int a = cnt; // шагов до цикла + шагов в цикле
            for (auto& a : visited) for (auto& b : a) b = 0;
            cnt = 0;
            dfs(endr, endc);
            int b = cnt; // шагов в цикле
            printf("%d step(s) before a loop of %d step(s)\n", a-b, b);
        }
        else printf("%d step(s) to exit\n", cnt);

    }
}