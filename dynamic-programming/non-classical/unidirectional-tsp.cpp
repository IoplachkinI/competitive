#include <bits/stdc++.h>

using namespace std;

const int MAXM = 11, MAXN = 101;
int m, n; 

vector<vector<int>> matrix (MAXM, vector<int> (MAXN));
vector<vector<int>> memo (MAXM, vector<int> (MAXN));
vector<int> path(MAXN);

int rec(int row, int col){
    if (col == n) return 0;
    int& ans = memo[row][col];
    if (ans != -1) return ans;

    int a, b, c;
    //first go into the least branch lexicographically
    if (row == 0){
        a = rec(row, col+1);
        b = rec((row+1) % m, col+1);
        c = rec(m-1, col+1);
    }
    else if (row == m-1){
        a = rec(0, col+1);
        b = rec(row-1, col+1);
        c = rec(row, col+1);
    }
    else {
        a = rec(row-1, col+1);
        b = rec(row, col+1);
        c = rec((row+1)%m, col+1);
    }

    return ans = matrix[row][col] + min(min(a, b), c);
}


bool findpath(int row, int col, int rem){
    if (rem == 0 && col == n)  return true;
    if (memo[row][col] == rem){
        path[col] = row;
        if (row == 0){
            if (findpath(row, col+1, rem - matrix[row][col])) return true;
            if (findpath((row+1)%m, col+1, rem - matrix[row][col])) return true;
            if (findpath(m-1, col+1, rem - matrix[row][col])) return true;
        }
        else if (row == m-1){
            if (findpath(0, col+1, rem - matrix[row][col])) return true;
            if (findpath(row-1, col+1, rem - matrix[row][col])) return true;
            if (findpath(row, col+1, rem - matrix[row][col])) return true;
        }
        else {
            if (findpath(row-1, col+1, rem - matrix[row][col])) return true;
            if (findpath(row, col+1, rem - matrix[row][col])) return true;
            if (findpath((row+1)%m, col+1, rem - matrix[row][col])) return true;
        }
    }

    return false;
}


/*EXCEEDINGLY SLOW, OVER 3^100 operations
void gen(int row, int col){
    vector<int> a = curpath;
    if (col == n) {
        long long curcost = 0;
        for (int i = 0; i < n; i++)
            curcost += matrix[curpath[i]][i];
        if (curcost < bestcost || (curcost == bestcost && curpath < bestpath))
            bestpath = curpath;
        if (curcost < bestcost){
            bestcost = curcost;
        }
        return;
    }

    curpath[col] = row;
    gen((row-1 < 0) ? m-1 : row-1, col+1);
    gen(row, col+1);
    gen((row+1) % m, col+1);
}*/

int main(){
    while (true){
        cin >> m >> n;
        if (cin.eof()) break;

        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

        /*for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                printf("%2d ", matrix[i][j]);
            cout << "\n";
        }*/
        
        for (auto& a : memo) for (auto& b : a) b = -1;
        
        int bestcost = INT32_MAX;
        for (int i = 0; i < m; i++)
            bestcost = min(bestcost, rec(i, 0));
        
        for (int i = 0; i < m; i++)
            if (findpath(i, 0, bestcost)) break;

        for (int i = 0; i < n; i++){
            if (i) cout << " ";
            cout << path[i]+1;
        }
        cout << "\n" << bestcost << "\n";
    }
}