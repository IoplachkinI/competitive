#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(2, '\n');
    while (n){
        int maxDiff = n / 3;
        vector<int> v (n);
        vector<vector<int>> diff (n, vector<int> (n));
        map<int, set<int>> m;
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                diff[i][j] = v[j] - v[i];
                m[i].insert(diff[i][j]);
            }
        }

        bool good = true;

        for (int i = 0; i < n && good; i++){
            for (int j = i + 1; j < n && good; j++){
                if (abs(diff[i][j]) <= maxDiff && m[j].count(diff[i][j])) good = false;
            }
        }

        if (good) cout << "yes\n";
        else cout << "no\n";
        cin >> n;
        cin.ignore(2, '\n');
    }
}