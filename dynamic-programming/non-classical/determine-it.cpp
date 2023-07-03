#include <bits/stdc++.h>

using namespace std;

const int MAXN = 21;
int n;

vector<vector<long long>> v(MAXN, vector<long long>(MAXN));

long long rec(int i, int j){
    long long& cell = v[i][j];
    if (cell != -1) return cell;

    long long tmp = INT32_MIN;
    if (i < j){
        for (int k = i; k < j; k++)
            tmp = max(tmp, rec(i, k) + rec(k+1, j));
    }
    else {
        long long a = 0, b = 0;
        for (int k = i+1; k <= n; k++)
            a = max(a, rec(k, 1) + rec(k, j));
        for (int k = 1; k < j; k++)
            b = max(b, rec(i, k) + rec(n, k));
        
        tmp = a + b;
    }

    return cell = tmp;
}

int main(){
    while (true){
        for (auto& a : v) for (auto& b : a) b = -1;
        cin >> n;
        cin >> v[n][1];
        if (cin.eof()) break;

        cout << rec(1, n) << '\n';
    }
}