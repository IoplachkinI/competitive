#include <bits/stdc++.h>

using namespace std;

const int MAXRC = 50;
int r, c;
vector<vector<char>> v(MAXRC, vector<char>(MAXRC));
vector<int> dr {0, 1, 0, -1};
vector<int> dc {1, 0, -1, 0};

int floodfill(int _r, int _c, vector<vector<char>>& _v, char c1, char c2){
    if (_r >= r || _r < 0 || _c >= c || _c < 0 || _v[_r][_c] != c1) return 0;
    int cnt = 1;
    _v[_r][_c] = c2;
    for (int i = 0; i < 4; i++)
        cnt += floodfill(_r+dr[i], _c+dc[i], _v, c1, c2);
    return cnt;
}

void printv(vector<vector<char>>& _v = v){
    printf("\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            printf("%c", _v[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> r >> c;
        if (!r) break;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
            cin >> v[i][j];

        printf("Problem %d:\n", _case);
        while (true){
            int maxi = 0, maxj = 0, maxsize = 0;
            vector<vector<char>> tmp = v;
            for (int i = 0; i < r; i++) for (int j = 0; j < c; j++){
                if (tmp[i][j] == '.') continue;
                int cur = floodfill(i, j, tmp, tmp[i][j], '.');
                //printv(tmp);
                if (cur > maxsize || (cur == maxsize && v[i][j] < v[maxi][maxj])){
                    maxsize = cur;
                    maxi = i;
                    maxj = j;
                }
            }
            if (maxsize == 0) break;
            printf("%c %d\n", v[maxi][maxj], maxsize);
            floodfill(maxi, maxj, v, v[maxi][maxj], '.');
        }
    }
}
