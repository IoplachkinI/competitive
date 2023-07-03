#include <bits/stdc++.h>

using namespace std;

const int MAXVAL = 101;
int n, k;

vector<vector<unsigned long long>> memo (MAXVAL, vector<unsigned long long> (MAXVAL));

unsigned long long rec(int _n, int _k){
    if (_k == 1) return 1;
    if (_n > n) return 0;
    unsigned long long& ans = memo[_n][_k];
    if (ans != -1) return ans;
    unsigned long long tmp = 0;
    for (int i = 0; i <= _n; i++)
        tmp += rec(_n - i, _k - 1);
    return ans = tmp % 1000000;
}

int main(){
    for (auto& a : memo) for (auto& b : a) b = -1;
    while (true){
        cin >> n >> k;
        if (n + k == 0) break;

        cout << rec(n, k)<< '\n';
    }
}