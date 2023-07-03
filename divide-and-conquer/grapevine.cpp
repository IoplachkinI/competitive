#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    while (n || m){
        vector<vector<int>> v (n, vector<int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        
        int q;
        cin >> q;

        while (q--){
            int l, h;
            int side = 0;
            cin >> l >> h;
            for (int i = 0; i < n; i++){
                const auto& start = lower_bound(v[i].begin(), v[i].end(), l);
                if (start == v[i].end() || *start > h) continue;
                const auto& end = upper_bound(v[i].begin(), v[i].end(), h);

                int startind = distance(v[i].begin(), start);
                int endind = distance(v[i].begin(), end);

                int curside = 0;
                for (int j = startind + side; j < endind; j++){
                    curside = j - startind + 1;
                    if (i + curside - 1 >= n || i + curside - 1 < 0) continue;
                    if (v[i + curside - 1][startind] >= l && v[i + curside - 1][j] <= h) 
                        if (curside > side) side = curside;
                }
            }
            cout << side << '\n';
        }
        cout << "-\n";
        cin >> n >> m;
    }   
}