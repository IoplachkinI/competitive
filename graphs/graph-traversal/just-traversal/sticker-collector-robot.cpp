#include <bits/stdc++.h>

using namespace std;




int main(){
    const int MAXN = 101, MAXM = 101;
    int n, m, s, cr = 1, cc = 1, dirind = 0, cnt; //sr - cur row
    string instr;
    vector<vector<char>> field(MAXN, vector<char> (MAXM));

    map<char,int> charToDirInd {
        {'N', 0},
        {'L', 1},
        {'S', 2},
        {'O', 3}
    };

    map <int, pair<int, int>> dirindToStep {
        {0, {-1, 0}},
        {1, {0, 1}},
        {2, {1, 0}},
        {3, {0, -1}}
    };

    while (true){
        cin >> n >> m >> s;
        cnt = 0;
        if (!n) break;

        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
            cin >> field[i][j];
            if (field[i][j] != '.' && field[i][j] != '*' && field[i][j] != '#') {
                cr = i;
                cc = j;
                dirind = charToDirInd[field[i][j]];
            }
        }
        
        cin >> instr;

        for (int i = 0; i < s; i++){
            if (instr[i] == 'F') {
                cr += dirindToStep[dirind].first;
                cc += dirindToStep[dirind].second;
                if (cr > n || cr < 1 || cc > m || cc < 1 || field[cr][cc] == '#') {
                    cr -= dirindToStep[dirind].first;
                    cc -= dirindToStep[dirind].second;
                }
                if (field[cr][cc] == '*') {
                    field[cr][cc] = '.';
                    cnt++;
                }
            }
            else if (instr[i] == 'D') dirind = (dirind + 1 > 3) ? 0 : dirind+1;
            else dirind = (dirind - 1 < 0) ? 3 : dirind-1;
        }

        cout << cnt << '\n';

    }
}