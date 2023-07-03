#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cas = 0;
    cin >> n;

    while (n--){
        cas++;
        int r, c;
        cin >> r >> c;

        vector<vector<int>> v (c, vector<int> (r));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++){
                char c;
                cin >> c;
                if (c == '1') v[j][i] = 1;
                else v[j][i] = 0;
            }

        int minMoves = INT32_MAX;
        for (int i = 0; i < c; i++){
            int moves = 0;
            bool possible = true;
            for (int j = 0; j < r && possible; j++){
                possible = !v[i][j];
                if (v[i][j]){
                    int localMinMoves = INT32_MAX;
                    for (int k = i + 1; k < c; k++)
                        if (!v[k][j]) {
                            possible = true;
                            localMinMoves = k - i;
                            break;
                        }
                    for (int k = i - 1; k > -1; k--)
                        if (!v[k][j]) {
                            possible = true;
                            if (i - k < localMinMoves) localMinMoves = i - k;
                            break;
                        }
                    moves += localMinMoves;
                }
                else continue;

            }
            if (!possible) break;
            if (moves < minMoves) minMoves = moves;
        }

        if (minMoves == INT32_MAX) minMoves = -1;

        printf("Case %d: %d\n", cas, minMoves);
    }
}