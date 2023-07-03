#include <bits/stdc++.h>

using namespace std;


const int MAXN = 10;
int n;
vector<vector<int>> v (MAXN, vector<int> (MAXN));

long long floodfill(int offset){
    long long cnt = 0;
    for (int i = offset; i < n-offset; i++){
        cnt += v[offset][i];
        v[offset][i] = 0;
        cnt += v[n-offset-1][i];
        v[n-offset-1][i] = 0;
        cnt += v[i][offset];
        v[i][offset] = 0;
        cnt += v[i][n-offset-1];
        v[i][n-offset-1] = 0;
    }
    return cnt;
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> n;
        if (!n) break;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            cin >> v[i][j];
        vector<long long> ans(n/2 + (n%2 == 1));
        for (int i = 0; i < ans.size(); i++){
            ans[i] = floodfill(i);
        }
        printf("Case %d:", _case);
        for (const auto& a : ans) printf(" %lld", a);
        printf("\n");
    }
}