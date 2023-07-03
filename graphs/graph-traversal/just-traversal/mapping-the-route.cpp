#include <bits/stdc++.h>

using namespace std;

const int MAXR = 14, MAXC = 14; // буфера по краям
int r, c, sr, sc, er, ec; // rows, columns, starting row/column, endpoint row/column

vector<vector<int>> v (MAXR, vector<int> (MAXC)); //v[i][j] = 1 - стена справа, 2 - стена снизу, 3 - стена и там, и там
stack<pair<int, int>> path;
vector<vector<int>> visited (MAXR, vector<int> (MAXC));

bool found;
void dfs(int curr, int curc){
    visited[curr][curc] = 1;
    path.push({curr, curc});
    stack<pair<int, int>> a = path;
    if (curr == er && curc == ec) found = true;
    
    //WNES
    if (!found && curc-1 > 0 && !visited[curr][curc-1] && v[curr][curc-1] != 1 && v[curr][curc-1] != 3)
        dfs(curr, curc-1);
    if (!found && curr-1 > 0 && !visited[curr-1][curc] && v[curr-1][curc] != 2 && v[curr-1][curc] != 3)
        dfs(curr-1, curc);
    if (!found && curc+1 <= c && !visited[curr][curc+1] && v[curr][curc] != 1 && v[curr][curc] != 3)
        dfs(curr, curc+1);
    if (!found && curr+1 <= r && !visited[curr+1][curc] && v[curr][curc] != 2  && v[curr][curc] != 3)
        dfs(curr+1, curc);

    if (!found) path.pop();
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> r >> c >> sr >> sc >> er >> ec;
        if (!r) break;

        found = false;
        for (auto& a : v) for (auto&b : a) b = 0;
        for (auto& a : visited) for (auto&b : a) b = 0;

        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
            cin >> v[i][j];
        }

        /*for (const auto& a : v){
            for (const auto& b : a)  
                cout << b;
            cout << '\n';
        } */

        dfs(sr, sc);

        map <pair<int, int>, int> coordToPathNum;
        int ind = path.size();
        while (!path.empty()){
            coordToPathNum[{path.top().first, path.top().second}] = ind;
            ind--;
            path.pop();
        }

        printf("Maze %d\n\n", _case);

        for (int i = 1; i <= c; i++) printf("+---");
        printf("+\n");

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++){
                if (j == 1 || v[i][j-1] == 1 || v[i][j-1] == 3) printf("|");
                else printf(" ");

                if (coordToPathNum.count({i, j})) printf("%3d", coordToPathNum[{i, j}]);
                else if (visited[i][j]) printf("???");
                else printf("   ");
            }
            printf("|\n");

            if (i == r) break;
            for (int j = 1; j <= c; j++){
                if (v[i][j] == 2 || v[i][j] == 3) printf("+---");
                else printf("+   ");
            }

            printf("+\n");
        }

        for (int i = 1; i <= c; i++) printf("+---");
        printf("+\n");

        printf("\n\n");
    }
}