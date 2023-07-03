#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int k;
        long long s = 0;
        cin >> k;
        vector<int> a (k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            for (int j = i - 1; j >= 0; j--){
                s += a[i] >= a[j];
            }
        };
        
        cout << s << '\n';
    }
}