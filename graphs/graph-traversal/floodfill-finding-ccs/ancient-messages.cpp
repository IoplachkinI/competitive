#include <bits/stdc++.h>

using namespace std;

int h, w;
const int MAXH = 200, MAXW = 200;
vector<vector<int>> v (MAXH, vector<int> (MAXW));

map<char, string> hexToBin {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'a', "1010"},
    {'b', "1011"},
    {'c', "1100"},
    {'d', "1101"},
    {'e', "1110"},
    {'f', "1111"}
};


map <int, char> whitesToName {
    {0, 'W'},
    {1, 'A'},
    {2, 'K'},
    {3, 'J'},
    {4, 'S'},
    {5, 'D'}
};

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};


bool matrixEdgeMet;
void floodfill(int r, int c, int c1, int c2){
    if (r >= h || r < 0 || c >= w * 4 || c < 0) {
        matrixEdgeMet = true;
        return;
    }
    if (v[r][c] != c1) return;
    v[r][c] = c2;
    for (int i = 0; i < 4; i++)
        floodfill(r+dr[i], c+dc[i], c1, c2);
}

int countWhites(int cborder, int c1, int c2){
    int whites = 0;
    for (int i = 0; i < h; i++) for (int j = 0; j < 4 * w; j++){
        if (v[i][j] != c1) continue;
        bool touchingBorder = false;
        for (int k = 0; k < 4; k++){
            int r = i + dr[k];
            int c = j + dc[k];
            if (r >= h || r < 0 || c >= w * 4 || c < 0) continue;
            if (v[r][c] == cborder) touchingBorder = true;
        }
        if (!touchingBorder) continue;
        matrixEdgeMet = false;
        whites++;
        floodfill(i, j, c1, c2);
        if (matrixEdgeMet) whites--;
    }
    return whites;
}

void printv(){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < 4*w; j++)
            printf("%2d", v[i][j]);
        printf("\n");
    } 
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> h >> w;
        if (!h) break;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){
            char in;
            cin >> in;
            string bin = hexToBin[in];
            v[i][j*4] = bin[0]-'0';
            v[i][j*4+1] = bin[1]-'0';
            v[i][j*4+2] = bin[2]-'0';
            v[i][j*4+3] = bin[3]-'0';
        }
        priority_queue<char, vector<char>, greater<char>> ans;
        //printv();
        for (int i = 0; i < h; i++) for (int j = 0; j < 4 * w; j++){
            if (v[i][j] == 1) {
                floodfill(i, j, 1, -1);
                //printv();
                ans.push(whitesToName[countWhites(-1, 0, 2)]);
                //printv();
                floodfill(i, j, -1, 2);
                //printv();
            }
        }
        printf("Case %d: ", _case);
        while (!ans.empty()){
            printf("%c", ans.top());
            ans.pop();
        }
        printf("\n");
    }
}