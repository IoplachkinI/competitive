#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int r;
        cin >> r;
        vector<int> v (r);
        for (int i = 0; i < r; i++){
            cin >> v[i];
        }
        int min = INT32_MAX;
        for (int i = 0; i < r; i++){
            int dist = 0;
            for (int j = 0; j < r; j++){
                dist += abs(v[i] - v[j]);
            }
            if (dist < min) min = dist;
        }
        cout << min << '\n';
    }
}