#include <bits/stdc++.h>

using namespace std;

const int H = 10, W = 15;
vector<vector<char>> v (H, vector<char>(W));
vector<int> dr {0, 1, 0, -1};
vector<int> dc {1, 0, -1, 0};

void printv(){
    printf("\n");
    for (const auto& a : v) {
        for (const auto& b : a) printf("%c", b);
        printf("\n");
    }
    printf("\n");
}

int floodfill(int r, int c, vector<vector<char>>& _v, char c1, char c2){
    if (r >= H || r < 0 || c >= W || c < 0 || _v[r][c] != c1) return 0;
    int cnt = 1;
    _v[r][c] = c2;  
    for (int i = 0; i < 4; i++)
        cnt += floodfill(r + dr[i], c + dc[i], _v, c1, c2);
    return cnt;
}  

void movec(){
    for (int i = 0; i < W; i++) {
        int firstdot = -1;
        for (int j = H-1; j >= 0; j--) {
            if (v[j][i] == '.' && firstdot == -1) {
                firstdot = j;
            }
            else if (v[j][i] != '.' && firstdot != -1) {
                v[firstdot][i] = v[j][i];
                v[j][i] = '.';
                firstdot--;
            }
        }
    }
}

void mover(){
    int firstcol = -1;
    for (int i = 0; i < W; i++) {
        bool empty = true;
        for (int j = 0; j < H && empty; j++){
            if (v[j][i] != '.') empty = false;
        }
        if (empty && firstcol == -1) firstcol = i;
        else if (!empty && firstcol != -1) {
            for (int j = 0; j < H; j++) {
                v[j][firstcol] = v[j][i];
                v[j][i] = '.';
            }
            firstcol++;
        }
    }
}

int main(){
    vector<vector<char>> tmp (H, vector<char>(W));
    int t, _case = 0;
    cin >> t;
    while (t--){
        _case++;
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
            cin >> v[i][j];
        
        printf("Game %d:\n\n", _case);
        int move = 0, totalscore = 0;
        while (true){
            move++;
            tmp = v;
            int maxballs = 0, totalballs = 0, maxi = 0, maxj = 0, curscore = 0;
            char maxcolor = ' ';
            for (int i = 0; i < W; i++) for (int j = H-1; j >= 0; j--){
                if (tmp[j][i] == '.') continue;
                int curballs = floodfill(j, i, tmp, tmp[j][i], '.');
                totalballs += curballs;
                if (curballs > maxballs){
                    maxballs = curballs;
                    maxi = i;
                    maxj = j;
                }
            }
            if (maxballs == 0) {
                totalscore += 1000;
            }
            if (maxballs < 2){
                printf("Final score: %d, with %d balls remaining.\n", totalscore, totalballs);
                break;
            }
            maxcolor = v[maxj][maxi];
            curscore = (maxballs-2)*(maxballs-2);
            totalscore += curscore;
            //printv();
            floodfill(maxj, maxi, v, v[maxj][maxi], '.');
            //printv();
            movec();
            //printv();
            mover();
            //printv();
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", 
                move, H-maxj, maxi+1, maxballs, maxcolor, curscore);
        }
        if (t) printf("\n");

    }
}
