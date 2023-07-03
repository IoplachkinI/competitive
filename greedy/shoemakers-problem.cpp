#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> v (n, vector<int> (3));
        for (int i = 0; i < n; i++){
            cin >> v[i][0];
            cin >> v[i][1];
            v[i][2] = i;
        }

        sort(v.begin(), v.end(), [](vector<int> i, vector<int> j){
            double ratioi = (double)i[1] / i[0];
            double ratioj = (double)j[1] / j[0];
            if (fabs(ratioi - ratioj) < 0.00001) return i[2] < j[2];
            return ratioi > ratioj;
        });

        for (int i = 0; i < n; i++){
            if (i) cout << " ";
            cout << v[i][2] + 1;
        }
        cout << "\n";
        if (t) cout << "\n";
    }   
}