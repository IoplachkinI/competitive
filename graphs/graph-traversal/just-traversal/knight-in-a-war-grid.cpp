#include <bits/stdc++.h>

using namespace std;

int r, c, m, n, w, odd, even;
const int MAXRC = 101;

vector<vector<int>> field(MAXRC, vector<int>(MAXRC)); // 0 -unvisited, 1 - water, 2 - visited

void dfs(int _r, int _c){
    field[_r][_c] = 2;
    set<pair<int, int>> cells {
        {_r+m, _c+n},
        {_r+m, _c-n},
        {_r-m, _c+n},
        {_r-m, _c-n},
        {_r+n, _c+m},
        {_r+n, _c-m},
        {_r-n, _c+m},
        {_r-n, _c-m}
    };
    
    int cur = 0;
    for (const auto& a : cells) {
        if (a.first >= r || a.first < 0 || a.second >= c || a.second < 0 
            || field[a.first][a.second] == 1) continue;
        cur++;
        if (field[a.first][a.second] == 0) dfs(a.first, a.second);
    }
    //printf("%d %d: %d\n", _r, _c, cur);
    if (cur % 2 == 0) even++;
    else odd++;
}

int main(){
    int t, _case = 0;
    cin >> t;
    while (t--){
        _case++;
        odd = even = 0;
        cin >> r >> c >> m >> n;
        cin >> w;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) field[i][j] = 0;
        for (int i = 0; i < w; i++){
            int _r, _c;
            cin >> _r >> _c;
            field[_r][_c] = 1;
        }
        dfs(0, 0);
        /*for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << field[i][j] << ' ';
            cout << '\n';
        }*/
        printf("Case %d: %d %d\n", _case, even, odd);
    }
}