#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> lis(n), lds(n);
        for (int i = n - 1; i >= 0; i--){
            lds[i] = 1;
            lis[i] = 1;
            for (int j = i + 1; j < n; j++){
                lds[i] = max(lds[i], (lds[j] + 1) * (v[i] > v[j]));
                lis[i] = max(lis[i], (lis[j] + 1) * (v[i] < v[j]));
            }
        }

        int maxlen = 0;
        for (int i = 0; i < n; i++)
            maxlen = max(maxlen, lis[i] + lds[i] - 1);

        if(maxlen == 8)
            int amogus = 545;

        cout << maxlen << "\n";
    }
}