#include <bits/stdc++.h>

using namespace std;

const int MAXMN = 20;
int m, n;
vector<vector<char>> v(MAXMN, vector<char>(MAXMN));

vector<int> dr {0, 1, 0, -1};
vector<int> dc {-1, 0, 1, 0};

int floodfill(int r, int c, char c1, char c2){
    if (r < 0 || r >= m) return 0;
    if (c < 0) c = n-1;
    else c %= n;

    if (v[r][c] != c1) return 0;
    v[r][c] = c2;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
        cnt += floodfill(r+dr[i], c+dc[i], c1, c2);
    return cnt;
}

int main(){
    while (true){
        cin >> m >> n;
        if (cin.eof()) break;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) 
            cin >> v[i][j];

        int r, c;
        cin >> r >> c;
        char land = v[r][c], water = v[r][c];
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) 
            if (v[i][j] != land) {
                water = v[i][j];
                break;
            }
        if (water == land) {
            printf("0\n");
            continue;
        }
        floodfill(r, c, land, water);
        int maxland = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (v[i][j]!=land) continue;
            int cur = floodfill(i, j, land, water);
            maxland = max(maxland, cur);
        }
        printf("%d\n", maxland);
    }
}