#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 100;
vector<vector<char>>v (MAXN, vector<char>(MAXN));
vector<int> dr {0, 1, 0, -1};
vector<int> dc {-1, 0, 1, 0};


bool afloat;
void floodfill(int r, int c, char cship, char chit, char cwater){
    if (r >= n || c >= n || r < 0 || c < 0 || v[r][c] == cwater) return;
    if (v[r][c] == cship) afloat = true;
    v[r][c] = cwater;
    for (int i = 0; i < 4; i++)
        floodfill(r+dr[i], c+dc[i], cship, chit, cwater);
}


int main(){
    int t, _case = 0;
    cin >> t;
    while (t--){
        _case++;
        cin >> n;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            cin >> v[i][j];
        
        int cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
            if (v[i][j] == '.') continue;
            afloat = false;
            floodfill(i, j, 'x', '@', '.');
            if (afloat) cnt++;
        }

        printf("Case %d: %d\n", _case, cnt);
    }
}