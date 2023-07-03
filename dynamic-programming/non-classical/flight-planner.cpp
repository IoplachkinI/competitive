#include <bits/stdc++.h>

using namespace std;

const int MAXH = 10, MAXL = 1000;
const int RISECOST = 60, STAYCOST = 30, SINKCOST = 20;
int x;

vector<vector<int>> memo (MAXH, vector<int> (MAXL));
vector<vector<int>> v (MAXH, vector<int> (MAXL));

int rec(int h, int l){
    if (l == x / 100) {
        if (h) return INT32_MAX / 4;
        return 0;
    }
    int& ans = memo[h][l];
    if (ans != -1) return ans;

    int a, b, c;
    if (!h) a = INT32_MAX / 4;
    else a = rec(h-1, l+1) + SINKCOST - v[h][l];
    b = rec(h, l+1) + STAYCOST - v[h][l];
    if (h == MAXH-1) c = INT32_MAX / 4;
    else c = rec(h+1, l+1) + RISECOST - v[h][l];

    return ans = min(min(a, b), c);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        for (auto& a : memo) for (auto& b : a) b = -1;
        cin >> x;
        for (int i = MAXH-1; i >= 0; i--) for (int j = 0; j < x / 100; j++)
            cin >> v[i][j];

        cout << rec(0, 0) << "\n\n";
    }
}