#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
int n;
vector<vector<int>> v (MAXN, vector<int> (MAXN));

void floodfill(int x, int y){
    if (x >= n || x < 0 || y >= n || y < 0 || v[x][y] != 1) return;
    v[x][y] = 2;

    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i == 0 && j == 0) continue;
            floodfill(x + i, y + j);
        }
    }
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        int cnt = 0;
        cin >> n;
        if (cin.eof()) break;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
            char in;
            cin >> in;
            v[i][j] = in - '0';
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
            if (v[i][j] == 1){
                cnt++;
                floodfill(i, j);
            }
        }
        printf("Image number %d contains %d war eagles.\n", _case, cnt);
    }
}