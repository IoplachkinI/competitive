#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    while (!cin.eof()){
        vector<vector<pair<int, int>>> res;
        for (int i = 0; i < n; i++) {
            res.push_back(vector<pair<int, int>>());
        }
        for (int i = 0; i < m; i++){
            int r;
            cin >> r;
            vector<pair<int, int>> ind(r);
            vector<vector<int>> v (r);
            for (int j = 0; j < r; j++) cin >> ind[j].first;
            for (int j = 0; j < r; j++) cin >> ind[j].second;
            for (int j = 0; j < r; j++) {
                res[ind[j].first - 1].push_back({i + 1, ind[j].second});
            }
        }
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < n; i++){
            cout << res[i].size();
            for (int j = 0; j < res[i].size(); j++) cout << ' ' << res[i][j].first;
            cout << '\n';
            for (int j = 0; j < res[i].size(); j++) {
                if (j) cout << ' ';
                cout << res[i][j].second;
            }
            cout << '\n';
        }
        cin >> m >> n;
    }
}