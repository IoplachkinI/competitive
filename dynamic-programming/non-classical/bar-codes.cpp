#include <bits/stdc++.h>

using namespace std;

const int MAXVAL = 51;
int n, k, m;

vector<vector<vector<long long>>> memo(MAXVAL, vector<vector<long long>> (MAXVAL, vector<long long>(MAXVAL)));

long long rec(int _n, int _k, int _m){
    if (_n == n && _k == k) return 1;
    if (_n >= n || _k >= k) return 0;
    long long& ans = memo[_n][_k][_m];
    if (ans != -1) return ans;
    long long tmp = 0;
    for (int i = 1; i <= m; i++)
        tmp += rec(_n+i, _k+1, max(i, _m));
    return ans = tmp;
}

int main(){
    while (true){
        cin >> n >> k >> m;
        if (cin.eof()) break;
        for (auto& a : memo) for (auto& b : a) for (auto& c : b) c = -1;
        cout << rec(0, 0, 0) << '\n';
    }
}