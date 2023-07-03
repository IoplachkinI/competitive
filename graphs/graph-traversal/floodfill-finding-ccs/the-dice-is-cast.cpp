#include <bits/stdc++.h>

using namespace std;

const int MAXWH = 50;
int w, h;
vector<vector<char>> v(MAXWH, vector<char>(MAXWH));
vector<int> dr {1, 0, -1, 0};
vector<int> dc {0, 1, 0, -1};


void printv(int r, int c){
    printf("\n");
    printf("  ");
    for (int i = 0; i < w; i++) {
        if (i == c) printf("|");
        else printf(" ");
    }
    printf("\n");
    for (int i = 0; i < h; i++) {
        if (i == r) printf("--");
        else printf("  ");
        for (int j = 0; j < w; j++) printf("%c", v[i][j]);
        printf("\n");
    }
}


int floodfill(int r, int c, char c1, char c2, char c3){
    //printv(r, c);
    if (r >= h || r < 0 || c >= w || c < 0 || (v[r][c] != c1 && v[r][c] != c2)) return 0;
    int cnt = 0;
    if (v[r][c] == c2) {
        cnt++;
        floodfill(r, c, c2, ' ', c1);
    }
    if (v[r][c] == c1) v[r][c] = c3;
    //printv(r, c);
    for (int i = 0; i < 4; i++)
        cnt += floodfill(r+dr[i], c+dc[i], c1, c2, c3);
    return cnt;
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> w >> h;
        if (!w) break;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
            cin >> v[i][j];

        priority_queue<int, vector<int>, greater<int>> res;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
            if (v[i][j] != '.') res.push(floodfill(i, j, '*', 'X', '.'));
        
        printf("Throw %d\n", _case);
        int _size = res.size();
        for (int i = 0; i < _size; i++) {
            if (i) printf(" ");
            printf("%d", res.top());
            res.pop();
        }
        printf("\n\n");
        
    }
}