#include <bits/stdc++.h>

using namespace std;

const int MAXN = 66;
long long memo [MAXN][2][MAXN];
int n, s;

//prec/cur = 1 - locked
long long rec(int id, int prev, int cnt){
    if (id == n && cnt == s) return 1;
    if (id == n) return 0;
    long long& ans = memo[id][prev][cnt];
    if (ans != -1) return ans;
    return ans = rec(id+1, 0, cnt) + rec(id+1, 1, cnt + prev);
}

int main(){
    while (true){
        cin >> n >> s;
        if (n < 0 && s < 0) break;
        memset(memo, -1, sizeof memo);

        cout << rec(0, 1, 0) << '\n';
    }
}