#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 201, MAXD = 21, MAXM = 11;
int n, q, d, m;
vector<int> v;

vector<vector<vector<int>>> memo (MAXN, vector<vector<int>> (MAXD, vector<int> (MAXM)));

ll rec(int id, ll rem, ll remm){
    if (remm == 0 && rem == 0) {
        return 1;
    }
    if (remm == 0 || id == n) return 0;
    int& ans = memo[id][rem][remm];
    if (ans != -1) {
        return ans;
    }
    long long new_rem = (rem+v[id])%d;
    if (rem+v[id] < 0) new_rem = (d - (-(rem+v[id])%d)) % d;
    return ans = rec(id+1, rem, remm) + rec(id+1, new_rem, remm-1);
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> n >> q;
        if (n + q == 0) break;
        v.resize(n);

        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        printf("SET %d:\n", _case);
        for (int i = 0; i < q; i++){
            cin >> d >> m;
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXD; k++)
                    for (int l = 0; l < MAXM; l++)
                        memo[j][k][l] = -1;

            long long ans = rec(0, 0, m);
            printf("QUERY %d: %lld\n", i+1, ans);
        }

    }

}